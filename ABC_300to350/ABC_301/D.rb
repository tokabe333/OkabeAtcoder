s = gets.chomp
n = gets.chomp.to_i 
nn = n

s.length.times do |i|
	ex = s.length - i - 1
	if s[i] == "1"
		n -= 2 ** ex
	end
end

if n < 0
	puts -1
	exit
end

s.length.times do |i|
	ex = s.length - i - 1
	ex2 = 2 ** ex
	next if s[i] == "0" || s[i] == "1"
	next if ex2 > n 
	n -= ex2 	
end
puts nn - n