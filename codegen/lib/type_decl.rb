# Type declaration
class TypeDecl
  attr_reader :name
  attr_accessor :is_class, :is_struct, :is_nullable, :is_inout, :size

  def initialize(name:, is_class: false, is_struct: false, is_nullable: false, is_inout: false, size: nil)
    @name = name
    @is_class = is_class
    @is_struct = is_struct
    @is_nullable = is_nullable
    @is_inout = is_inout
    @size = size
  end
end
