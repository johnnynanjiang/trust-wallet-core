# Function or method declaration
class FunctionDecl
  attr_reader :name
  attr_accessor :is_method, :return_type, :parameters, :static

  def initialize(name:, is_method:, return_type: :void, parameters: [], static: false)
    @name = name
    @is_method = is_method
    @return_type = return_type
    @parameters = parameters
    @static = static
  end
end

# Function parameter
class Parameter
  attr_reader :name, :type

  def initialize(name:, type:)
    @name = name
    @type = type
  end
end
