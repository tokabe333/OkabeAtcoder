n = gets.chomp.to_i 

arr = Array.new(n)
n.times do |i|
	c = gets.chomp.to_i 
	arr[i] = gets.chomp.split.map(&:to_i)
end

x = gets.chomp.to_i 

ans = Array.new(1000).map{Array.new}
n.times do |i|
	next if arr[i].index{|a| a == x} == nil 
	ans[arr[i].length] << (i + 1)
end

ans.length.times do |i|
	next if ans[i].length == 0
	puts ans[i].length
	puts ans[i].join(" ")
	exit
end	

puts 0 
puts
