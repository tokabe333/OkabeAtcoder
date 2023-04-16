gets
s = gets.chomp.chars
(s.length - 1).times do |i|
	if s[i] == s[i + 1]
		puts "No"
		exit
	end
end
puts "Yes"