q = gets.chomp.to_i 
arr = []
q.times do |i|
	c, x = gets.chomp.split.map(&:to_i)
	if c == 1   
		arr << x   
	else 
		puts arr[arr.length - x]
	end
end