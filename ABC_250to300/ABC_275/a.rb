1
1000000000
n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i)

max = 0
index = 0
arr.length.times do |i|
	if max < arr[i]
		max = arr[i]
		index = i 
	end
end

puts index + 1