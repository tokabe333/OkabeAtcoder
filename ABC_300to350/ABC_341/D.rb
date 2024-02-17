

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



lcm = LCM(n, m)

nn = lcm / n - 1
mm = lcm / m - 1

once = nn + mm 
kaisu = k / once 
k = k % once 

if k == 0
	kaisu -= 1
	k = once
end	

l = 0
r = lcm + 1000
mid = 0
# while (l - r).abs > 1
while(true)
	mid = (l + r) / 2

	num = mid / n + mid / m 

	if num < k  
		l = mid
	elsif num > k
		r = mid
	elsif num == k
		
		 puts "l:#{l} r:#{r} mid:#{mid}"
		mid = mid / [n, m].max * [n, m].max 
		break
	end


end



puts "lcm:#{lcm} kaisu:#{kaisu} once:#{once} mid:#{mid} k:#{k}"

puts lcm * kaisu + mid