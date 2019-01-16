# frozen_string_literal: true

module JavaHelper
  # Transforms an interface name to a Java method name
  def self.format_name(name)
    return 'equals' if name == 'Equal'

    result = name
    match = /^([A-Z]+)/.match(name)
    result = name.sub(match[1], match[1].downcase) unless match.nil?

    result.sub(/_/, '')
  end

  # Transforms an interface name to a Java constant name
  def self.format_constant(name)
    name.upcase
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
      'byte'
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
