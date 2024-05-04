s = gets.chomp
t = gets.chomp 

ans = []

ind = 0
s.chars.each do |c|
	while t[ind] != c  
		ind += 1
	end
	ans << ind + 1
	ind += 1
end

puts ans.join(" ")