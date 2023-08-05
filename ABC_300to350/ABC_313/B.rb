require "set"
n, m = gets.chomp.split.map(&:to_i)
mat = Array.new(n).map{Array.new(n, 0)}
m.times do |i|
	a, b = gets.chomp.split.map{|c| c.to_i - 1}
	mat[b][a] = 1
end

# n.times do |i|
# 	p mat[i]
# end

anss = []
tail = []
n.times do |i|
	num = 0
	n.times do |y|
		num += mat[y][i]
	end
	if num == 0
		tail << i + 1
	end

	if mat[i].inject(:+) == 0
		anss << i + 1
	end
end

# p anss 
# p tail
if anss.length == 1 #&& tail.length == 1
	puts anss[0]
else
	puts -1
end