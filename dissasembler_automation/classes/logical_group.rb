require_relative 'processor_8080_registers'

class LogicalGroup < Processor8080Registers
  # AND
  #-------------------------------------------------------------------------------------------------------------------
  AND_REGISTER = REGISTERS.map { |register, binary| new("ANA #{register}", "10100#{binary}") }

  AND_MEMORY = new('ANA M', '10100110')

  AND_IMMEDIATE = new('ANI D%02x', '11100110', printf_args: 'code[1]', opbytes: 2)

  # Exclusive OR
  #-------------------------------------------------------------------------------------------------------------------
  EXCLUSIVE_OR_REGISTER = REGISTERS.map { |register, binary| new("XRA #{register}", "10101#{binary}") }

  EXCLUSIVE_OR_MEMORY = new('XRA M', '10101110')

  EXCLUSIVE_OR_IMMEDIATE = new('XRI D#$%02x', '11101110', printf_args: 'code[1]', opbytes: 2)

  # OR
  #-------------------------------------------------------------------------------------------------------------------
  OR_REGISTER = REGISTERS.map { |register, binary| new("ORA #{register}", "10110#{binary}") }

  OR_MEMORY = new('ORA M', '10110110')

  OR_IMMEDIATE = new('ORI #$%02x', '11110110', printf_args: 'code[1]', opbytes: 2)

  # COMPARE
  #-------------------------------------------------------------------------------------------------------------------
  COMPARE_REGISTER = REGISTERS.map { |register, binary| new("CMP #{register}", "10111#{binary}") }

  COMPARE_MEMORY = new('CMP M', '10111110')

  COMPARE_IMMEDIATE = new('CPI D#$%02x', '11111110', printf_args: 'code[1]', opbytes: 2)

  # ROTATE
  #-------------------------------------------------------------------------------------------------------------------
  ROTATE_LEFT = new('RLC', '00000111')

  ROTATE_RIGHT = new('RRC', '00001111')

  ROTATE_LEFT_THROUGH_CARRY = new('RAL', '00010111')

  ROTATE_RIGHT_THROUGH_CARRY = new('RAR', '00011111')

  # MISC
  #-------------------------------------------------------------------------------------------------------------------
  COMPLEMENT_ACCUMULATOR = new('CMA', '00101111')

  COMPLEMENT_CARRY = new('CMC', '00111111')

  SET_CARRY = new('STC', '00110111')

  #-------------------------------------------------------------------------------------------------------------------

  AND = [*AND_REGISTER, AND_MEMORY, AND_IMMEDIATE].freeze

  EXCLUSIVE_OR = [*EXCLUSIVE_OR_REGISTER, EXCLUSIVE_OR_MEMORY, EXCLUSIVE_OR_IMMEDIATE].freeze

  OR = [*OR_REGISTER, OR_MEMORY, OR_IMMEDIATE].freeze

  COMPARE = [*COMPARE_REGISTER, COMPARE_MEMORY, COMPARE_IMMEDIATE].freeze

  ROTATE = [ROTATE_LEFT, ROTATE_RIGHT, ROTATE_LEFT_THROUGH_CARRY, ROTATE_RIGHT_THROUGH_CARRY].freeze

  MISC = [COMPLEMENT_ACCUMULATOR, COMPLEMENT_CARRY, SET_CARRY].freeze

  def self.operations
    [
      *AND,
      *EXCLUSIVE_OR,
      *OR,
      *COMPARE,
      *ROTATE,
      *MISC
    ]
  end
end
