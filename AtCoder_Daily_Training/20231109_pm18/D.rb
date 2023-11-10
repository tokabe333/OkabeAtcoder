n, x, y, z = gets.chomp.split.map(&:to_i)
arr = Array.new(n)
math = gets.chomp.split.map(&:to_i)
eng  = gets.chomp.split.map(&:to_i)

n.times do |i|
	arr[i] = [math[i], eng[i], i + 1]
end


ans = Array.new

arr = arr.sort{|a, b| [-a[0], a[2]] <=> [-b[0], b[2]]}
x.times do |i|
	ans << arr[0][2]
	arr.shift 
end

arr = arr.sort{|a, b| [-a[1], a[2]] <=> [-b[1], b[2]]}
y.times do |i|
	ans << arr[0][2]
	arr.shift 
end

arr = arr.sort{|a, b| [-a[0] - a[1], a[2]] <=> [-b[0] - b[1], b[2]]}
z.times do |i|
	ans << arr[i][2]
end	

puts ans.sort.join("\n")