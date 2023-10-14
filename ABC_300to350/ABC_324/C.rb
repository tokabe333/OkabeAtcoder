n, tt = gets.chomp.split 
n = n.to_i 
ans = []
1.upto(n) do |i|
	s = gets.chomp 
	next if (s.length - tt.length).abs > 1
	
	if s.length == tt.length
		if s == tt 
			ans << i 
			next  
		end
		flag = 0
		s.length.times do |j|
			if s[j] != tt[j]
				flag += 1 
				break if flag == 2
			end
		end
		ans << i if flag < 2
	end

	# s < ss
	t = tt.chomp 
	if s.length > t.length  
		s, t = t, s 
	end

	si = 0
	ti = 0
	flag = 0
	while si < s.length || ti < t.length
		if s[si] != t[ti]
			flag += 1
			ti += 1
			break if flag == 2
			next 
		end
		si += 1 
		ti += 1
	end
	#puts "si:#{si} ti:#{ti} i:#{i} flag:#{flag}"
	ans << i if flag <= 1
end

puts ans.length
puts ans.join(" ")