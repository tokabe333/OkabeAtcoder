n = gets.chomp.to_i 
fsqn = ((n / 12.0) ** (1 / 2.0)).ceil
puts "fsqn : #{(n / 12.0) ** (1 / 2.0)}"

eratos = Array.new(fsqn, 1)
eratos[0] = 0
eratos[1] = 0
2.upto(fsqn - 1) do |i|
	next if fsqn[i] == 0 
	ii = i * 2
	while ii <= fsqn 
		eratos[ii] = 0
		ii += i   
	end		
end

p eratos
