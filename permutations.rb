
destiny_source_registers = permutations(REGISTERS.keys.join(''))
self_destiny_source_registers = REGISTERS.keys.join('').split('').map { |letter| letter * 2 }

destiny_source_registers += self_destiny_source_registers

def create_process_obj(name, binary, opbytes: 1, printf_args: nil)
  {
    name: name,
    hex: bin_to_hex(binary),
    opbytes: opbytes,
    printf_args: printf_args
  }
end

DESTINY_SOURCE_REGS = destiny_source_registers.map do |register_pair|
  r1, r2 = register_pair.split('')
  ["#{r1}, #{r2}", "#{REGISTERS[r1]}#{REGISTERS[r2]}"]
end


# Data Tran

def move_register(ds_registers)
  ds_registers.map do |register_combination, binary_value|
    create_process_obj("MOV #{register_combination}", "01#{binary_value}")
  end
end

def move_to_and_from_memory
  to = REGISTERS.map do |register, binary|
    create_process_obj("MOV #{register}, M", "01#{binary}110")
  end

  from = REGISTERS.map do |register, binary|
    create_process_obj("MOV M, #{register}", "01110#{binary}")
  end

  (from + to)
end

MVI_M_REGISTER = { 'M' => '110' }.freeze
def immediate_move
  REGISTERS.merge(MVI_M_REGISTER).map do |register, binary|
    create_process_obj(
      "MVI #{register} #$%02x$02x",
      "00#{binary}110",
      printf_args: 'code[2], code[1]',
      opbytes: 2
    )
  end
end

# Load register pair immediate
def lxi_rp
  REGISTER_PAIRS.map do |rp, binary|
    create_process_obj(
      "LXI #{rp}, #$%02x$02x",
      "00#{binary}0001",
      printf_args: 'code[2], code[1]',
      opbytes: 3
    )
  end
end

load_acumulator_direct = create_process_obj('LDA addr', '00111010', opbytes: 3)

store_accumulator_direct = create_process_obj('STA addrs', '00110010', opbytes: 3)

load_h_and_l_direct = create_process_obj('LHDL addr', '00101010', opbytes: 3)

store_h_and_l_direct = create_process_obj('SHLD addr', '00100010', opbytes: 3)

# Content of the memory location, whose address is in the register pair rp, is moved into register A.
# Only registers B-C or D-E can be specified
def load_acumulator_indirect
  REGISTER_PAIRS.slice('B-C', 'D-E').map do |rp, binary|
    create_process_obj("LDAX #{rp}", "00#{binary}1010")
  end
end

# Content of refisrer A is moved to the meory location whose address is in the register pair rp
# Only registers B-C or D-E can be specified
def store_accumulator_indirect
  REGISTER_PAIRS.slice('B-C', 'D-E').map do |rp, binary|
    create_process_obj("STAX #{rp}", "00#{binary}0010")
  end
end

exchange_h_and_l_with_d_and_e = create_process_obj('XCHG', '11101011')

operations = [
  *move_register(DESTINY_SOURCE_REGS),
  *move_to_and_from_memory,
  *immediate_move,
  *lxi_rp,
  load_acumulator_direct,
  store_accumulator_direct,
  load_h_and_l_direct,
  store_h_and_l_direct,
  *load_acumulator_indirect,
  *store_accumulator_indirect,
  exchange_h_and_l_with_d_and_e
]

def format_output(operation)
  printf_args = ", #{operation[:printf_args]}" unless operation[:printf_args].nil?
  print_name = "printf(\"#{operation[:name]}\"#{printf_args})"

  byte_cost = "opbytes = #{operation[:opbytes]}"

  commands = [print_name, byte_cost, 'break;']

  case_clause = "case 0x#{operation[:hex]}"

  puts " #{case_clause}: #{commands.join('; ')}"
end

operations.sort { |op1, op2| op1[:hex] <=> op2[:hex] }.each do |operation|
  format_output(operation)
end
