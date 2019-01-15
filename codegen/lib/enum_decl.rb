# frozen_string_literal: true

# Enum declaration.
class EnumDecl
  attr_reader :name
  attr_accessor :cases

  def initialize(name:)
    @name = name
    @cases = []
  end
end

# Enum case declaration.
class EnumCaseDecl
  attr_reader :name
  attr_accessor :enum, :value

  def initialize(name:, enum:, value: nil)
    @name = name
    @enum = enum
    @value = value
  end
end
