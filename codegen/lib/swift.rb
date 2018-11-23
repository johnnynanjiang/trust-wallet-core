module Swift
  # Transforms an interface name to a Swift method or property name
  def self.format_name(n)
    return '< ' if n == 'Less'
    return '== ' if n == 'Equal'

    prefix = /^([A-Z]+)/.match(n)[1]
    return n if prefix.nil?
    n.sub(prefix, prefix.downcase)
  end

  def self.parameters(params)
    names = params.map do |param|
      "#{param.name || '_ value'}: #{type(param.type)}"
    end
    names.join(', ')
  end

  def self.arguments(params)
    params.map do |param|
      if param.type.name == :data && param.type.is_inout
        'ptr'
      elsif param.type.name == 'Data'
        "#{param.name || 'value'}.twData"
      elsif param.type.is_struct || param.type.is_class
        "#{param.name || 'value'}.rawValue"
      elsif param.type.name == :int
        "Int32(#{param.name || 'value'})"
      else
        param.name || 'value'
      end
    end.join(', ')
  end

  def self.type(t)
    case t.name
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
      if t.is_inout
        'inout Data'
      else
        'Data'
      end
    when :string
      if t.is_inout
        'inout String'
      else
        'String'
      end
    else
      t.name
    end
  end
end
