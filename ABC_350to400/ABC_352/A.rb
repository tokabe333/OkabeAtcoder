n, x, y, z = gets.chomp.split.map(&:to_i)

if (x <= z && z <= y) || (-x <= -z && -z <= -y)
	puts "Yes"
else
	puts "No"
end