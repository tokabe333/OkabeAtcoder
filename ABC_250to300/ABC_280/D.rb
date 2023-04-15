require "prime"
require "set"

debug = true

k = gets.chomp.to_i 
kp = Prime.prime_division(k)

ans = 0
kp.each do |hoge|
	pr = hoge[0]
	a = hoge[1]
	
	n = 0
	while a > 0 
		n += pr 
		x = n 
		while x % pr == 0
			x /= pr
			a -= 1
		end
	end
	ans = n if ans < n  
end

puts ans


