def bin_to_hex(binary)
  format('%02x', binary.to_i(2))
end

# Ruby already has a nicer 'permutation' method for strings
# But I just wanted to do my own for fun
def permutations(str, subsets: 1, max_subsets: 2)
  return str.chars if subsets == max_subsets

  str.chars.each.with_index.reduce([]) do |perms, (letter, i)|
    chars = str.chars.dup
    chars.delete_at(i)
    substr = chars.join('')
    mixed = []

    mixed = permutations(substr, subsets: subsets + 1, max_subsets: max_subsets) unless substr.empty?
    mixed = mixed.map { |mix| letter + mix }

    perms.concat(mixed)
  end
end
