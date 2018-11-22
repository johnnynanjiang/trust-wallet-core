require 'erb'
require 'java'
require 'jni'
require 'swift'

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

  def render_java
    render('java.erb')
  end

  def render_jni_h
    render('jni_h.erb')
  end

  def render_jni_c
    render('jni_c.erb')
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
end
