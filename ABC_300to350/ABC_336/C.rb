n = gets.chomp.to_i - 1
n5 = n.to_s(5)
n5.length.times do |i|
	n5[i] = (n5[i].to_i * 2).to_s
end
puts n5