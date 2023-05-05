n = gets.chomp.to_i 
puts "? 1"
prev_value = gets.chomp.to_i 
prev_lowhigh = -1
left = 0
right = n
count = 0

while left + 1 < right && count < 20
	middle = (left + right) / 2
	puts "? #{middle + 1}"
	value = gets.chomp.to_i 
	prev_lowhigh *= -1 if value == prev_value
	
	if prev_lowhigh == -1
		left = middle 
	else
		right = middle
	end

	count += 1
end