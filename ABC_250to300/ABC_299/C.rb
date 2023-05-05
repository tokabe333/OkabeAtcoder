n = gets.chomp.to_i 
str = gets.chomp

maru = false 
batu = false 
n.times do |i|
	maru = true if str[i] == "o"
	batu = true if str[i] == "-"
end

if maru == false || batu == false 
	puts -1 
	exit
end

#arr = str.split("-").map{|s| s.length}
#p arr
puts str.split("-").map{|s| s.length}.max 