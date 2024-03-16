x = gets.chomp.to_i
if x % 10 == 0
	puts x / 10
else
	x /= 10
	x += 1
	puts x 
end