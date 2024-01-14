n = gets.chomp.to_i
s = n.to_s(2)

cnt = 0
s.length.times do |i|
	break if s[s.length - i - 1] != "0"
	cnt += 1
end

puts cnt