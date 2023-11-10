b = gets.chomp.to_i 
i = 1
while i ** i <= b   
	if i ** i == b  
		puts i    
		exit 
	end
	i += 1
end

puts -1
