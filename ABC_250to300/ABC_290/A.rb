n, m = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i)
brr = gets.chomp.split.map(&:to_i)

ans = 0
brr.each do |b|
	ans += arr[b - 1]
end
puts ans