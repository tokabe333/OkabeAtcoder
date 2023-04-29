x = gets.chomp.to_i
x += 10 ** 19
if x > 0 
	x = x - (x % 10)
elsif x < 0 && x % 10 != 0
	x = x - (10 - x % 10)
end

x -= 10 ** 19
puts x / 10