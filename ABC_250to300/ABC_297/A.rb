n, d = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i)
(n - 1).times do |i|
	if arr[i + 1] - arr[i] <= d 
		puts arr[i + 1]
		exit
	end
end
puts "-1"