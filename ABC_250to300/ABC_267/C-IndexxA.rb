n, m  = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i)

ans = 0
num = 1.0
(n - m).times do |i|
	num *= arr[i]
end
ans = num 

m.times do |i|
	num /= arr[n - 1 - i]
	num *= arr[i]
	ans = num if ans < num 
end

puts ans.to_i
