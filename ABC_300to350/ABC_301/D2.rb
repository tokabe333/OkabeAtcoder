s = gets.chomp
n = gets.chomp.to_i 

s.length.times do |i|
	ex = s.length - i - 1 
	next if s[i] == "0"
	n -= 2 ** ex 
end

if n < 0 
	puts -1
	exit
end

s = s.rjust(100, "0")
n2 = n.to_s(2).rjust(100, "0")

puts n
puts s 
puts n2

left = false 
s.length.times do |i|
	left = true if n2[i] == "1"

	if s[i] == "0"
		next 
	elsif s[i] == "1"

	else
end
