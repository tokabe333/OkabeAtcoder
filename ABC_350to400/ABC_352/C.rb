n = gets.chomp.to_i 

arr = Array.new(n)
n.times do |i|
	arr[i] = gets.chomp.split.map(&:to_i)
end

brr = arr.sort{|a,b| [-a[0], -a[1]] <=> [-b[0], -b[1]]}

p brr