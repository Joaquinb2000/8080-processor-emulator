require_relative '../utils'

class Processor8080Registers
  attr_accessor :name, :hex, :opbytes, :printf_args

  def initialize(name, binary, opbytes: 1, printf_args: nil)
    @name = name
    @hex = bin_to_hex(binary)
    @opbytes = opbytes
    @printf_args = printf_args
  end

  REGISTERS = {
    'B' => '000',
    'C' => '001',
    'D' => '010',
    'E' => '011',
    'H' => '100',
    'L' => '101',
    'A' => '111'
  }.freeze

  REGISTER_PAIRS = {
    'B-C' => '00',
    'D-E' => '01',
    'H-L' => '10',
    'SP' => '11'
  }.freeze

  CONDITIONS = {
    'NZ' => '000',  # not zero (Z = 0)
    'Z' => '001',   # zero (Z = 1)
    'NC' => '010',  # no carry (CY = 0)
    'C' => '011',   # carry (CY = 1)
    'PO' => '100',  # parity odd (P = 0)
    'PE' => '101',  # parity even (P = 1)
    'P' => '110',   # plus (S = 0)
    'M' => '111'    # minus (S = 1)
}.freeze

  # Contains ['AA', 'BB', 'CC', ...] Register combinations
  SELF_DESTINY_SOURCE_REGS_NAMES = REGISTERS.keys.join('').split('').map { |letter| letter * 2 }.freeze

  # Contains ['AB', 'AC', ..., 'BC', 'BD', ...] Register combinations
  DESTINY_SOURCE_REG_NAMES = (permutations(REGISTERS.keys.join('')) + SELF_DESTINY_SOURCE_REGS_NAMES).freeze

  # Contains array containing two element arrays with the format: [['A, B', "#{binary_value_combination}"], ...]
  DESTINY_SOURCE_REGS = DESTINY_SOURCE_REG_NAMES.map do |register_pair|
    r1, r2 = register_pair.split('')
    ["#{r1}, #{r2}", "#{REGISTERS[r1]}#{REGISTERS[r2]}"]
  end

  def to_s
    super
    printf_arguments = ", #{printf_args}" unless printf_args.nil?
    print_name = "printf(\"#{name}\"#{printf_arguments})"

    byte_cost = "opbytes = #{opbytes}"

    commands = [print_name, byte_cost, 'break;']

    case_clause = "case 0x#{hex}"

    " #{case_clause}: #{commands.join('; ')}"
  end
end
