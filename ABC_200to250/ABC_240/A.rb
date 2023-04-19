a, b = gets.chomp.split.map(&:to_i)
a, b = b, a if a > b 
if a == 1 && b == 10 || a + 1 == b   
	puts "Yes"
else 
	puts "No"
end