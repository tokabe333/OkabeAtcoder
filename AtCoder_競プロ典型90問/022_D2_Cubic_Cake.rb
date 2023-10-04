
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

a, b, c = gets.chomp.split.map(&:to_i)

g = GCD(a, GCD(b, c))
ans = (a / g - 1) + (b / g - 1) + (c / g - 1)
puts ans