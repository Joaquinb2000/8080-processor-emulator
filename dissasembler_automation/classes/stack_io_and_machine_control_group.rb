require_relative 'processor_8080_registers'

class StackIoAndMachineControlGroup < Processor8080Registers
  RELEVANT_REGISTER_PAIRS = REGISTER_PAIRS.slice(REGISTER_PAIRS.keys - ['SP'])

  PUSH = RELEVANT_REGISTER_PAIRS.map { |register_pair, binary| new("PUSH #{register_pair}", "11#{binary}0101") }

  PUSH_PROCESSOR_STATUS_WORD = new('PUSH PSW', '11110101')

  POP = RELEVANT_REGISTER_PAIRS.map { |register_pair, binary| new("POP #{register_pair}", "11#{binary}0001") }

  POP_PROCESSOR_STATUS_WORD = new('POP PSW', '11110001')

  EXCH_STACK_TOP_WITH_H_AND_L = new('XTHL', '11100011')

  MOVE_HL_TO_SP = new('SPHL', '11111001')

  INPUT = new('IN port', '11011011')

  OUTPUT = new('OUT port', '11010011')

  ENABLE_INTERRUPTS = new('EI', '11111011')

  DISABLE_INTERRUPTS = new('DI', '11110011')

  HALT = new('HLT', '01110110')

  NO_OP = new('NOP', '00000000')

  def self.operations
    [
      *PUSH,
      *POP,
      PUSH_PROCESSOR_STATUS_WORD,
      POP_PROCESSOR_STATUS_WORD,
      EXCH_STACK_TOP_WITH_H_AND_L,
      MOVE_HL_TO_SP,
      INPUT,
      OUTPUT,
      ENABLE_INTERRUPTS,
      DISABLE_INTERRUPTS,
      HALT,
      NO_OP
    ]
  end
end
