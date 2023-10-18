n, x = gets.chomp.split.map(&:to_i)
arr = Array.new(n)
brr = Array.new(n)
n.times do |i|
	arr[i], brr[i] = gets.chomp.split.map(&:to_i)
end

ans = Array.new(n)
time = 0
n.times do |i|
	time += arr[i] + brr[i]
	ans[i] = time + brr[i] * (x - (i + 1))
end

puts ans.min
p ans