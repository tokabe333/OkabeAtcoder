n = gets.chomp.to_i

enum = []
[true, false].repeated_permutation(10) do |bits|
# [true, false].permutation(10) do |bits|
	num = 0
	9.downto(0) do |i|
		next if bits[i] == false 
		num = num * 10 + i
	end
	enum << num
end

enum = enum.uniq.sort
# p enum 
p enum[n]