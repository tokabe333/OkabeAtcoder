s = gets.chomp
n = gets.chomp.to_i 

s.length.times do |i|
	ex = s.length - i - 1 
	n -= 2 ** ex if s[i] == "1"
end

if n < 0 
	puts -1
	exit
end

s = s.rjust(100, "0")
n2 = n.to_s(2).rjust(100, "0")

# puts n
# puts s 
# puts n2

left = 0
ans = 0
s.length.times do |i|
	if n2[i] == "1"
		left = s[i] == "0" ? 2 : 1
	end
	
	ex = s.length - i - 1

	if s[i] == "0"
		next 
	elsif s[i] == "1"
		if left == 0
			puts -1
			exit
		end
		ans += 2 ** ex 
		left = 0 if left == 1
	else
		if left == 0
			next 
		elsif left == 1
			ans += 2 ** ex 
			left = 0
		else
			ans += 2 ** ex
		end
	end
end

puts ans