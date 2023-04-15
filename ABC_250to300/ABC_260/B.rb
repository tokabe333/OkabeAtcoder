n, x, y, z = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i)
brr = gets.chomp.split.map(&:to_i)

person = Array.new(n)
n.times do |i|
	person[i] = [arr[i], brr[i], i + 1]
end

passed = Array.new 
person = person.sort{|a, b| [-a[0], a[2]] <=> [-b[0], b[2]]}
x.times do 
	passed << person.shift
end

person = person.sort{|a, b| [-a[1], a[2]] <=> [-b[1], b[2]]}
y.times do 
	passed << person.shift 
end

person = person.sort{|a, b| [-a[0] - a[1], a[2]] <=> [-b[0] - b[1], b[2]]}
z.times do 
	passed << person.shift 
end

puts passed.sort{|a, b| a[2] <=> b[2]}.map{|pa| pa[2]}