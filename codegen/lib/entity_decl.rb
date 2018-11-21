# Class or struct declaration
class EntityDecl
  attr_reader :name
  attr_accessor :is_struct, :methods, :properties, :static_methods, :static_properties

  def initialize(name:, is_struct:)
    @name = name
    @is_struct = is_struct
    @methods = []
    @properties = []
    @static_methods = []
    @static_properties = []
  end
end
