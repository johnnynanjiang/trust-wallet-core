# Type declaration
class TypeDecl
  attr_reader :name
  attr_accessor :is_struct, :is_nullable

  def initialize(name:, is_struct:, is_nullable: false)
    @name = name
    @is_struct = is_struct
    @is_nullable = is_nullable
  end
end
