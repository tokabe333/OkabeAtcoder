n = gets.chomp.to_i
s = gets.chomp

ans = 0
(n-2).times do |i|
	ans += 1 if s[i] == "#" && s[i + 1] == "." && s[i + 2] == "#"
end

puts ans