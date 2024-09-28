ans = 0

12.times do |i|
	s = gets.chomp
	ans += 1 if s.length == i + 1
end

puts ans