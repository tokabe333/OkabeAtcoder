n = gets.chomp.to_i 
snum =  gets.chomp 
s = format("%014d", "9" + snum).chars.sort 
s.pop

snum = snum.to_i

Limit = 10 ** n
ans = 0
i = 1 
ii = i * i
while ii < Limit 
	hoge = format("%013d", ii.to_s).chars.sort 
	if s == hoge 
		ans += 1
		#puts "i:#{i} ii:#{i*i} hoge:#{hoge.join(' ')}"
	end
	i += 1
	ii = i * i
end

puts ans