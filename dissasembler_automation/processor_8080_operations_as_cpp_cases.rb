require './classes/data_transfer_group'
require './classes/arithmetic_group'
require './classes/logical_group'
require './classes/branch_group'

operations = [
  *DataTransferGroup.operations,
  *ArithmeticGroup.operations,
  *LogicalGroup.operations,
  *BranchGroup.operations
]

operations.sort { |op1, op2| op1.hex <=> op2.hex }.each do |operation|
  puts operation
end
