n = gets.chomp.to_i 

a = Array.new(n)
n.times do |i|
	a[i] = gets.chomp.split.map(&:to_i)
end

b = Array.new(n)
n.times do |i|
	b[i] = gets.chomp.split.map(&:to_i)
end

4.times do |i|
	a = a.transpose.map(&:reverse)
	
	flag = true
	n.times do |y|
		n.times do |x|
			flag = false if a[y][x] == 1 && b[y][x] == 0
		end
	end
	if flag 
		puts "Yes"
		exit
	end
end
puts "No"