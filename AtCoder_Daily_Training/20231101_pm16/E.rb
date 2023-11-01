s = gets.chomp
ans = 0
s.length.times do |i|
	ans += 26**(s.length - i - 1) * (s[i].ord - "A".ord + 1)
end

puts ans