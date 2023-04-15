n = gets.chomp.to_i
cnt = 0 
n.times do |i|
	cnt += 1 if gets[0] == "F"
end 
puts cnt >= n / 2.0 ? "Yes" : "No"