# frozen_string_literal: true

# Type declaration
class TypeDecl
  attr_reader :name
  attr_accessor :is_class, :is_struct, :is_enum, :is_nullable, :is_inout, :size

  def initialize(name:, is_class: false, is_struct: false, is_enum: false, is_nullable: false, is_inout: false, size: nil)
    @name = name
    @is_class = is_class
    @is_struct = is_struct
    @is_enum = is_enum
    @is_nullable = is_nullable
    @is_inout = is_inout
    @size = size
  end

  def self.fromPrimitive(string)
    case string
    when 'void'
      TypeDecl.new(name: :void)
    when 'bool'
      TypeDecl.new(name: :bool)
    when 'int'
      TypeDecl.new(name: :int)
    when 'size_t'
      TypeDecl.new(name: :size)
    when 'uint8_t'
      TypeDecl.new(name: :uint8)
    when 'uint16_t'
      TypeDecl.new(name: :uint16)
    when 'uint32_t'
      TypeDecl.new(name: :uint32)
    when 'uint64_t'
      TypeDecl.new(name: :uint64)
    else
      nil
    end
  end
end
