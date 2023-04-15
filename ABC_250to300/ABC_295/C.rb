hash = Hash.new(0)
n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i)

arr.each do |a|
	hash[a] += 1
end

ans = 0
hash.each do |key, value|
	ans += value / 2
end

puts ans