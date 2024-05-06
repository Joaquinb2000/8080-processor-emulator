# frozen_string_literal: true

require_relative 'processor_8080_registers'

# Data transfer group operations
class DataTransferGroup < Processor8080Registers
  MVI_M_REGISTER = { 'M' => '110' }.freeze

  def self.move_register
    DESTINY_SOURCE_REGS.map do |register_combination, binary_value|
      new("MOV #{register_combination}", "01#{binary_value}")
    end
  end

  def self.move_to_and_from_memory
    to = REGISTERS.map do |register, binary|
      new("MOV #{register}, M", "01#{binary}110")
    end

    from = REGISTERS.map do |register, binary|
      new("MOV M, #{register}", "01110#{binary}")
    end

    (from + to)
  end

  def self.immediate_move
    REGISTERS.merge(MVI_M_REGISTER).map do |register, binary|
      new(
        "MVI #{register} #$%02x%02x",
        "00#{binary}110",
        printf_args: 'code[2], code[1]',
        opbytes: 2
      )
    end
  end

  # Load register pair immediate
  def self.lxi_rp
    REGISTER_PAIRS.map do |rp, binary|
      new(
        "LXI #{rp}, #$%02x%02x",
        "00#{binary}0001",
        printf_args: 'code[2], code[1]',
        opbytes: 3
      )
    end
  end

  # Content of the memory location, whose address is in the register pair rp, is moved into register A.
  # Only registers B-C or D-E can be specified
  def self.load_acumulator_indirect
    REGISTER_PAIRS.slice('B-C', 'D-E').map do |rp, binary|
      new("LDAX #{rp}", "00#{binary}1010")
    end
  end

  # Content of refisrer A is moved to the meory location whose address is in the register pair rp
  # Only registers B-C or D-E can be specified
  def self.store_accumulator_indirect
    REGISTER_PAIRS.slice('B-C', 'D-E').map do |rp, binary|
      new("STAX #{rp}", "00#{binary}0010")
    end
  end

  LOAD_ACUMULATOR_DIRECT = new('LDA addr', '00111010', opbytes: 3)

  STORE_ACCUMULATOR_DIRECT = new('STA addrs', '00110010', opbytes: 3)

  LOAD_H_AND_L_DIRECT = new('LHDL addr', '00101010', opbytes: 3)

  STORE_H_AND_L_DIRECT = new('SHLD addr', '00100010', opbytes: 3)

  EXCHANGE_H_AND_L_WITH_D_AND_E = new('XCHG', '11101011')

  def self.operations
    [
      *move_register,
      *move_to_and_from_memory,
      *immediate_move,
      *lxi_rp,
      *load_acumulator_indirect,
      *store_accumulator_indirect,
      LOAD_ACUMULATOR_DIRECT,
      STORE_ACCUMULATOR_DIRECT,
      LOAD_H_AND_L_DIRECT,
      STORE_H_AND_L_DIRECT,
      EXCHANGE_H_AND_L_WITH_D_AND_E
    ]
  end
end
