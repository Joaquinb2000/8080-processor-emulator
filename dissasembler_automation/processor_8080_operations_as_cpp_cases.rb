require './classes/data_transfer_group'

operations = [
  *DataTransferGroup.operations
]

operations.sort { |op1, op2| op1.hex <=> op2.hex }.each do |operation|
  puts operation
end
