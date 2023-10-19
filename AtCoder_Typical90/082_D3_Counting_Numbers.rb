l, r = gets.chomp.split.map(&:to_i)
ld = l.to_s.length 
rd = r.to_s.length 
MOD = 10 ** 9 + 7

#puts "ld:#{ld} rd:#{rd}"
ans = 0
ld.upto(rd) do |d|
	sita = [l, 10 ** (d - 1)].max 
	ue = [r, 10 ** d - 1].min
	#puts "d:#{d} sita:#{sita} ue:#{ue}"
	num = ue - sita + 1
	ans = ans + num * (sita + ue) / 2 * d 
	ans %= MOD 
end

puts ans
