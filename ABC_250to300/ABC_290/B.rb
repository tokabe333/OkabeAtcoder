n, m = gets.chomp.split.map(&:to_i)
s = gets.chomp 

ans = ""
count = 0
s.chars.each do |c|
	if c == "x"
		ans += c  
	else
		if count < m 
			ans += "o"
			count += 1
		else
			ans += "x"
		end
	end
end

puts ans