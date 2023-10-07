s = gets.chomp
1.upto(s.length - 1) do |i|
	next if i % 2 == 0 
	if s[i] == "1"
		puts "No"
		exit
	end
end
puts "Yes"
