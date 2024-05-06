require_relative 'processor_8080_registers'
require_relative '../utils'

class BranchGroup < Processor8080Registers
  JUMP = new('JMP addr', '11000011', opbytes: 3)

  CONDITIONAL_JUMP = CONDITIONS.map { |condition, binary| new("JC #{condition}", "11#{binary}010", opbytes: 3) }

  CALL = new('CALL addr', '11001101', opbytes: 3)

  CONDITION_CALL = CONDITIONS.map { |condition, binary| new("CC #{condition}", "11#{binary}100", opbytes: 3) }

  RETURN = new('RET', '11001001')

  CONDTIONAL_RETURN = CONDITIONS.map { |condition, binary| new("Rcondition #{condition}", "11#{binary}000") }

  RESTART = (0..7).map { |n| new("RST #{n}", "11#{format('%03b', n)}111") }.freeze

  JMP_H_AND_L_IND_MOVE_H_AND_L_TO_PC = new('PCHL', '11101001')

  def self.operations
    [
      JUMP,
      *CONDITIONAL_JUMP,
      CALL,
      *CONDITION_CALL,
      RETURN,
      *CONDTIONAL_RETURN,
      *RESTART,
      JMP_H_AND_L_IND_MOVE_H_AND_L_TO_PC
    ]
  end
end
