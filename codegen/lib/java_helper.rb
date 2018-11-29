module JavaHelper
  # Transforms an interface name to a Java method name
  def self.format_name(n)
    return 'compareTo' if n == 'Less'
    return 'equals' if n == 'Equal'

    prefix = /^([A-Z]+)/.match(n)[1]
    return n if prefix.nil?
    n.sub(prefix, prefix.downcase)
  end

  def self.parameters(params)
    names = params.map do |param|
      "#{type(param.type)} #{param.name || 'value'}"
    end
    names.join(', ')
  end

  def self.arguments(params)
    params.map do |param|
      param.name || 'value'
    end.join(', ')
  end

  def self.type(t)
    case t.name
    when :void
      'void'
    when :bool
      'boolean'
    when :int
      'int'
    when :uint8
      'char'
    when :uint16
      'short'
    when :uint32
      'int'
    when :uint64
      'long'
    when :size
      'int'
    when :data
      'byte[]'
    when 'Data'
      'byte[]'
    when :string
      'String'
    else
      t.name
    end
  end
end
