module JNIHelper
  # Transforms an interface name to a JNI method name
  def self.format_name(n)
    return 'compareTo' if n == 'Less'
    return 'equals' if n == 'Equal'

    prefix = /^([A-Z]+)/.match(n)[1]
    return n if prefix.nil?
    n.sub(prefix, prefix.downcase)
  end

  # Transforms a method/property name to a JNI function name
  def self.function_name(entity:, function:, native_prefix: false)
    if native_prefix
      "Java_com_wallet_crypto_trustapp_jni_#{ entity.name }_native#{function.name}"
    else
      "Java_com_wallet_crypto_trustapp_jni_#{ entity.name }_#{format_name(function.name)}"
    end
  end

  def self.parameters(params)
    names = params.map do |param|
      ", #{type(param.type)} #{param.name || 'value'}"
    end
    names.join('')
  end

  def self.arguments(params)
    params.map do |param|
      if param.type.name == :data
        "#{param.name || 'value'}Buffer"
      elsif param.type.name == 'Data'
        "#{param.name || 'value'}Data"
      elsif param.type.name == :string
        "#{param.name || 'value'}Buffer"
      else
        param.name || 'value'
      end
    end.join(', ')
  end

  def self.type(t)
    case t.name
    when :void
      'void'
    when :bool
      'jboolean'
    when :int
      'jint'
    when :uint8
      'jchar'
    when :uint16
      'jshort'
    when :uint32
      'jint'
    when :uint64
      'jlong'
    when :size
      'jsize'
    when :data
      'jbyteArray'
    when 'Data'
      'jbyteArray'
    when :string
      'jstring'
    else
      if t.is_class || t.is_struct
        'jobject'
      else
        raise "Invalid type #{t.name}"
      end
    end
  end
end
