n = gets.chomp.to_i 

n.upto(919) do |i|
	s = i.to_s 
	a = s[0].to_i 
	b = s[1].to_i 
	c = s[2].to_i 
	#puts "i:#{i} a:#{a} b:#{b} c:#{c} "  
	if a * b == c   
		puts i    
		exit 
	end
end