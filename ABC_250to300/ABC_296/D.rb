n, m = gets.chomp.split.map(&:to_f)

if n >= m 
	puts "1 #{m.to_i}"
	exit
end

ans = 10 ** 15
sqm = Math.sqrt(m)
1.upto(sqm.to_i) do |a|
	b = m / a
	next if b > n
	c = a * b.ceil 
	if ans > c && c >= m
		ans = c
		#puts "a:#{a} b:#{b} c:#{c}"
	end
end
puts ans == 10 ** 15 ? -1 : ans