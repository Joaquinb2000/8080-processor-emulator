require_relative 'processor_8080_registers'

class ArithmeticGroup < Processor8080Registers
  # ADDITION
  #----------------------------------------------------------------------------------------------------
  ADD_REGISTER = REGISTERS.map { |register, binary| new("ADD #{register}", "1000#{binary}") }

  ADD_MEMORY = new('ADD M', '10000110')

  ADD_IMMEDIATE = new('ADI DATA, #$%02x', '11000110', printf_args: 'code[1]', opbytes: 2)

  ADD_REG_WITH_CARRY = REGISTERS.map do |register, binary|
    new("ADC #{register}", "10001#{binary}")
  end

  ADD_MEMORY_WITH_CARRY = new('ADC M', '10001110')

  ADD_IMMEDIATE_WITH_CARRY = new('ACI D, #$%02x', '11001110', printf_args: 'code[1]', opbytes: 2)

  # SUBSTRACTION
  #----------------------------------------------------------------------------------------------------
  SUBSTRACT_REGISTER = REGISTERS.map { |register, binary| new("SUB #{register}", "10010#{binary}") }

  SUBTRACT_MEMORY = new('SUB M', '10010110')

  SUBTRACT_IMMEDIATE = new('SUI DATA, #$%02x', '11010110', printf_args: 'code[1]', opbytes: 2)

  SUBTRACT_REG_WITH_BORROW = REGISTERS.map { |register, binary| new("SBB #{register}", "10011#{binary}") }

  SUBTRACT_MEM_WITH_BORROW = new('SBB M', '10011110')

  SUBTRACT_IMMEDIATE_WIH_BORROW = new('SBI data, #$%02x', '11011110', printf_args: 'code[1]', opbytes: 2)

  # INCREMENT
  #----------------------------------------------------------------------------------------------------
  INCREMENT_REGISTER = REGISTERS.map { |register, binary| new("INR #{register}", "00#{binary}100") }

  INCREMENT_MEMORY = new('INR M', '00110100')

  # DECREMENT
  #----------------------------------------------------------------------------------------------------
  DECREMENT_REGISTER = REGISTERS.map { |register, binary| new("DCR #{register}", "00#{binary}101") }

  DECREMENT_MEMORY = new('DCR M', '00110101')

  # REGISTER PAIR ARITHMETIC
  #----------------------------------------------------------------------------------------------------
  INCR_REGISTER_PAIR = REGISTER_PAIRS.map { |register_pair, binary| new("INX #{register_pair}", "00#{binary}0011") }

  DECR_REGISTER_PAIR = REGISTER_PAIRS.map { |register_pair, binary| new("DCX #{register_pair}", "00#{binary}1011") }

  ADD_REG_PAIR_TO_H_AND_L = REGISTER_PAIRS.slice('H-L').map do |register_pair, binary|
    new("DAD #{register_pair}", "00#{binary}1001")
  end

  # DECIMAL ADJUST
  #----------------------------------------------------------------------------------------------------
  DECIMAL_ADJUST_ACCUMULATOR = new('DAA', '00100111')
  #----------------------------------------------------------------------------------------------------

  ADD_OPERATIONS = [
    *ADD_REGISTER,
    ADD_MEMORY,
    ADD_IMMEDIATE,
    *ADD_REG_WITH_CARRY,
    ADD_MEMORY_WITH_CARRY,
    ADD_IMMEDIATE_WITH_CARRY
  ].freeze

  SUBTRACT_OPERATIONS = [
    *SUBSTRACT_REGISTER,
    SUBTRACT_MEMORY,
    SUBTRACT_IMMEDIATE,
    *SUBTRACT_REG_WITH_BORROW,
    SUBTRACT_MEM_WITH_BORROW,
    SUBTRACT_IMMEDIATE_WIH_BORROW
  ].freeze

  INCREMENT_OPERATIONS = [*INCREMENT_REGISTER, INCREMENT_MEMORY].freeze

  DECREMENT_OPERATIONS = [*DECREMENT_REGISTER, DECREMENT_MEMORY].freeze

  REGISTER_PAIR_ARITHMENTIC = [*INCR_REGISTER_PAIR, *DECR_REGISTER_PAIR, *ADD_REG_PAIR_TO_H_AND_L].freeze

  def self.operations
    [
      *ADD_OPERATIONS,
      *SUBTRACT_OPERATIONS,
      *INCREMENT_OPERATIONS,
      *DECREMENT_OPERATIONS,
      *REGISTER_PAIR_ARITHMENTIC,
      DECIMAL_ADJUST_ACCUMULATOR
    ]
  end
end
