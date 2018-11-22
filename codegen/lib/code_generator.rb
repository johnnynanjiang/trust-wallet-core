require 'erb'

# Code generation
class CodeGenerator
  attr_accessor :entity
  attr_reader :locals

  def initialize(entity:)
    @entity = entity
  end

  def render_swift
    render('swift.erb')
  end

  def render(file, locals = {})
    @locals = locals
    path = File.expand_path(file, File.join(File.dirname(__FILE__), 'templates'))
    template = ERB.new(File.read(path), nil, '-')
    template.result(binding)
  end

  def should_return_data(method)
    return false if method.parameters.empty?
    last = method.parameters.last
    last.type.name == :data && last.type.is_inout && !last.type.size.nil? &&
    (method.return_type.name == :void || method.return_type.name == :size)
  end

  # Transforms an interface name to a Swift method or property name
  def swift_name(name)
    return '<' if name == 'Less'
    return '==' if name == 'Equal'

    prefix = /^([A-Z]+)/.match(name)[1]
    return name if prefix.nil?
    name.sub(prefix, prefix.downcase)
  end

  def swift_parameters(params)
    names = params.map do |param|
      "#{param.name || '_ value'}: #{swift_type(param.type)}"
    end
    names.join(', ')
  end

  def swift_arguments(params)
    params.map do |param|
      if param.type.name == :data && param.type.is_inout
        'ptr'
      elsif param.type.name == 'Data'
        "#{param.name || 'value'}.twData"
      else
        param.name || 'value'
      end
    end.join(', ')
  end

  def swift_type(type)
    case type.name
    when :void
      'Void'
    when :bool
      'Bool'
    when :int
      'Int'
    when :uint32
      'UInt32'
    when :uint64
      'UInt64'
    when :size
      'Int'
    when :data
      if type.is_inout
        'inout Data'
      else
        'Data'
      end
    when :string
      if type.is_inout
        'inout String'
      else
        'String'
      end
    else
      type.name
    end
  end
end
