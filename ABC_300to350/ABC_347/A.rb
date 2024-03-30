n, k = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i)

ans  = []
arr.each do |a|
	next if a % k != 0
	ans << a / k
end
puts ans.join(" ")