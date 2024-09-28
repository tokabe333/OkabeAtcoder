s = gets.chomp
arr = Array.new(30, 0)

s.length.times do |i|
	arr[s[i].ord - "A".ord + 1] = i
end

ans = 0
2.upto(26) do |i|
	ans += (arr[i] - arr[i-1]).abs
end

puts ans