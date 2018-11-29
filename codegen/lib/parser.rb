require 'strscan'

require 'entity_decl'
require 'function_decl'
require 'type_decl'

# C header parser
class Parser
  attr_reader :path, :entity

  def initialize(path:, string: nil)
    @path = path
    @buffer = StringScanner.new(string || File.read(path))
    @entity = nil
  end

  # Parses a C header file for class/struct declarations
  def parse
    until @buffer.eos?
      # Look for TW_EXPORT statements
      break if @buffer.skip_until(/\n/).nil?
      @buffer.skip(/\s*/)
      next if @buffer.scan(/TW_EXPORT_[A-Z_]+/).nil?

      # Handle statements
      case @buffer[0]
      when 'TW_EXPORT_CLASS'
        handle_class
      when 'TW_EXPORT_STRUCT'
        handle_struct
      when 'TW_EXPORT_FUNC'
        handle_func
      when 'TW_EXPORT_METHOD'
        handle_method
      when 'TW_EXPORT_PROPERTY'
        handle_property
      when 'TW_EXPORT_STATIC_METHOD'
        handle_static_method
      when 'TW_EXPORT_STATIC_PROPERTY'
        handle_static_property
      end
    end

    @entity
  end

  # Parses a type.
  def parse_type
    @buffer.skip(/\s*/)
    if @buffer.scan(/struct TW(\w+) \*(_Nullable|_Nonnull)/)
      return TypeDecl.new(name: @buffer[1], is_class: true, is_nullable: @buffer[2] == '_Nullable')
    elsif @buffer.scan(/struct TW(\w+)/)
      return TypeDecl.new(name: @buffer[1], is_struct: true)
    elsif @buffer.scan(/uint8_t (\w+)\[(_Nullable|_Nonnull) (\w+)\]/)
      return TypeDecl.new(name: :data, is_nullable: @buffer[2] == '_Nullable', is_inout: true, size: @buffer[3])
    elsif @buffer.scan(/(const )?uint8_t \*(_Nullable|_Nonnull)/)
      return TypeDecl.new(name: :data, is_nullable: @buffer[2] == '_Nullable', is_inout: @buffer[1] != 'const ')
    elsif @buffer.scan(/(const )?char \*(_Nullable|_Nonnull)/)
      return TypeDecl.new(name: :string, is_nullable: @buffer[2] == '_Nullable', is_inout: @buffer[1] != 'const ')
    elsif @buffer.scan(/char (\w+)\[(_Nullable|_Nonnull) (\w+)\]/)
      return TypeDecl.new(name: :string, is_nullable: @buffer[2] == '_Nullable', is_inout: true, size: @buffer[3])
    elsif @buffer.scan(/void/)
      return TypeDecl.new(name: :void)
    elsif @buffer.scan(/bool/)
      return TypeDecl.new(name: :bool)
    elsif @buffer.scan(/int/)
      return TypeDecl.new(name: :int)
    elsif @buffer.scan(/size_t/)
      return TypeDecl.new(name: :size)
    elsif @buffer.scan(/uint8_t/)
      return TypeDecl.new(name: :uint8)
    elsif @buffer.scan(/uint16_t/)
      return TypeDecl.new(name: :uint16)
    elsif @buffer.scan(/uint32_t/)
      return TypeDecl.new(name: :uint32)
    elsif @buffer.scan(/uint64_t/)
      return TypeDecl.new(name: :uint64)
    else
      report_error 'Invalid type'
    end
  end

  # Parses a function prototype.
  def parse_func
    return_type = parse_type
    @buffer.skip(/\s*/)
    scan_or_fail(/\w+/, 'Invalid function name')

    func = FunctionDecl.new(name: @buffer[0], entity: @entity, is_method: true, return_type: return_type)
    @buffer.skip(/\s*/)

    scan_or_fail(/\(/, 'Invalid function declaration. Expected (')
    until @buffer.scan(/\)/)
      type = parse_type
      @buffer.skip(/\s*/)

      # Special case for `x f(void)`` style prototypes
      break if type.name == :void && @buffer.scan(/\)/)

      name = ''
      if type.name == :data && !type.size.nil?
        name = 'result'
      elsif type.name == :string && !type.size.nil?
        name = 'result'
      else
        name = @buffer.scan(/\w+/)
      end
      param = Parameter.new(name: name, type: type)
      func.parameters << param
      @buffer.skip(/\s*,\s*/)
    end

    @buffer.skip(/;/)
    func
  end

  def handle_class
    @buffer.skip(/\s*/)
    report_error 'Invalid type name' if @buffer.scan(/struct TW(\w+)\s*;/).nil?
    report_error 'Found more than one class/struct in the same file' unless @entity.nil?
    @entity = EntityDecl.new(name: @buffer[1], is_struct: false)
    puts "Found a class #{@entity.name}"
  end

  def handle_struct
    @buffer.skip(/\s*/)
    report_error 'Invalid type name at' if @buffer.scan(/struct TW(\w+)\s*\{?/).nil?
    report_error 'Found more than one class/struct in the same file' unless @entity.nil?
    @entity = EntityDecl.new(name: @buffer[1], is_struct: true)
    puts "Found a struct #{@buffer[1]}"
  end

  def handle_func
    report_error 'Free functions not supported'
  end

  def handle_method
    report_error 'Method found before class/struct definition' if @entity.nil?
    method = parse_func

    # Remove prefix
    unless method.name.start_with? "TW#{@entity.name}"
      report_error 'Method name needs to start with class/struct name'
    end
    method.name.slice! "TW#{@entity.name}"

    # Check first parameter
    if method.parameters.count.zero? || @entity.name != method.parameters.first.type.name
      report_error 'First parameter on a method needs to be the struct or class the method belongs to'
    end
    if @entity.is_struct && method.parameters.first.type.is_class
      report_error 'First parameter on a struct method needs to be the struct'
    end
    if !@entity.is_struct && !method.parameters.first.type.is_class
      report_error 'First parameter on a class method needs to be the class'
    end

    @entity.methods << method
  end

  def handle_property
    report_error 'Method found before class/struct definition' if @entity.nil?
    method = parse_func

    # Remove prefix
    unless method.name.start_with? "TW#{@entity.name}"
      report_error 'Method name needs to start with class/struct name'
    end
    method.name.slice! "TW#{@entity.name}"

    # Check first parameter
    if method.parameters.count < 1 || @entity.name != method.parameters.first.type.name
      report_error 'Only parameter on a property needs to be the struct or class the property belongs to'
    end
    if method.parameters.count == 2 && method.parameters[1].type.name != :data
      report_error "A property's second parameter can only be result data"
    end
    if method.parameters.count > 2
      report_error 'Only parameter on a property needs to be the struct or class the property belongs to'
    end
    if @entity.is_struct && method.parameters.first.type.is_class
      report_error 'Only parameter on a struct property needs to be the struct'
    end
    if !@entity.is_struct && !method.parameters.first.type.is_class
      report_error 'Only parameter on a class property needs to be the class'
    end

    @entity.properties << method
  end

  def handle_static_method
    report_error 'Method found before class/struct definition' if @entity.nil?
    method = parse_func

    # Remove prefix
    unless method.name.start_with? "TW#{@entity.name}"
      report_error "Static method name needs to start with class/struct name. Method name #{method.name} does not start with TW#{@entity.name}."
    end
    method.name.slice! "TW#{@entity.name}"

    @entity.static_methods << method
  end

  def handle_static_property
    report_error 'Method found before class/struct definition' if @entity.nil?
    method = parse_func

    # Remove prefix
    unless method.name.start_with? "TW#{@entity.name}"
      report_error 'Method name needs to start with class/struct name'
    end
    method.name.slice! "TW#{@entity.name}"

    unless method.parameters.count.zero?
      report_error 'Static properties can have no parameters'
    end

    @entity.static_properties << method
  end

  private

  def scan_or_fail(regex, error)
    report_error error if @buffer.scan(regex).nil?
  end

  def report_error(message)
    raise "#{@path}:#{current_line_number} #{message}"
  end

  def current_line_number
    @buffer.string[0..@buffer.pos].count("\n") + 1
  end
end
