# frozen_string_literal: true

require 'erb'
require 'java_helper'
require 'jni_helper'
require 'swift_helper'

# Code generation
class CodeGenerator
  attr_accessor :entities, :entity, :file
  attr_reader :locals

  def initialize(entities:,file:)
    @entities = entities
    @file = file
  end

  def render_swift
    result = String.new
    result << render('swift/header.erb')
    entities.each do |e|
      @entity = e
      string = render('swift.erb')
      unless string.nil? || string.empty?
        result << "\n"
        result << string
      end
    end
    result
  end

  def render_java
    result = String.new
    result << render('java/header.erb')
    entities.each do |e|
      @entity = e
      string = render('java.erb')
      unless string.nil? || string.empty?
        result << "\n"
        result << string
      end
    end
    result
  end

  def render_jni_h
    result = String.new
    entities.each do |e|
      @entity = e
      string = render('jni_h.erb')
      result << string unless string.nil?
    end
    result
  end

  def render_jni_c
    result = String.new
    entities.each do |e|
      @entity = e
      string = render('jni_c.erb')
      result << string unless string.nil?
    end
    result
  end

  def render(file, locals = {})
    @locals = locals
    path = File.expand_path(file, File.join(File.dirname(__FILE__), 'templates'))
    template = ERB.new(File.read(path), nil, '-')
    template.result(binding)
  end

  def should_return_data(method)
    return false if method.parameters.empty?

    method.return_type.name == :data
  end

  def should_return_string(method)
    return false if method.parameters.empty?

    method.return_type.name == :string
  end

  def should_return_object(method)
    method.return_type.is_struct || method.return_type.is_class
  end
end
