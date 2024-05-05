class Processor8080
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

  SELF_DESTINY_SOURCE_REGS = REGISTERS.keys.join('').split('').map { |letter| letter * 2 }.freeze
  DESTINY_SOURCE_REGS = (permutations(REGISTERS.keys.join('')) + SELF_DESTINY_SOURCE_REGS).freeze

  def bin_to_hex(binary)
    format('0x%02x', binary.to_i(2))
  end
end

def permutations(str, subsets: 1, max_subsets: 2)
  return str.split('') if subsets == max_subsets

  str.split('').each.with_index.reduce([]) do |perms, (letter, i)|
    substr = str.split('').filter.with_index { |_, j| i != j }.join('')
    mixed = []

    unless substr.empty?
      mixed = permutations(substr, subsets: subsets + 1)
      mixed = mixed.map { |mix| letter + mix }
    end

    perms.concat(mixed)
  end
end
