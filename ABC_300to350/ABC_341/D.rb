

def GCD(m, n)
	return 0 if m == 0 || n == 0
	while m != 0 && n != 0
		if m > n then
			m %= n
		else
			n %= m
		end
	end
	return [m, n].max
end

def LCM(m, n)
	return 0 if m == 0 || n == 0
	return m * n / GCD(m, n)
end

n, m, k = gets.chomp.split.map(&:to_i)
k -= 1

gcd = GCD(n, m)
n = n / gcd 
m = m / gcd

once = n + m - 2
lcm = LCM(n, m)
ans = lcm * (k / once)
kk = k % once 


nn = n 
mm = m 
kk.times do
	if nn < mm 
		nn += n  
	else
		mm += m  
	end
end

#puts "ans:#{ans} nn:#{nn} mm:#{mm}"
ans += [nn, mm].min 

puts ans * gcd

