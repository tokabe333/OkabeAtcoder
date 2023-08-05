n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i)
ave = arr.inject(:+) / n
puts "ave:#{ave}"

count = 0
while((arr.min - arr.max).abs > 1)
	tops = 0
	bottoms = 0
	n.times do |i|
		if arr[i] > ave 
			tops += arr[i] - ave 
			arr[i] -= arr[i] - ave
		elsif arr[i] < ave 
			bottoms += ave - arr[i]
		end
	end
	puts "tops:#{tops} bottoms:#{bottoms}"
	count += [tops, bottoms].min
end
#puts "tops:#{tops} bottoms:#{bottoms}"
ans = [tops, bottoms].max
puts ans.to_i