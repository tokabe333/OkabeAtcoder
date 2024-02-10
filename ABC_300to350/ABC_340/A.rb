 a, b, c = gets.chomp.split.map(&:to_i)
 i = a 
 while i <= b    
	print(i.to_s + " ")  
	i += c   
 end
 puts