n = gets.chomp.to_i
s = gets.chomp.chars

if s.index{|c| c == "o"} != nil && s.index{|c| c == "x"} == nil 
	puts "Yes"
else
	puts "No"
end
