n = gets.chomp.to_i
prr = gets.chomp.split.map{|x|  x.to_i - 1}
s = gets.chomp
m998 = 998244353
# .false #true
kakutei = "." * n
spun = "." * n
n.times do |i|
	p1 = prr[i]
	p2 = (p1 + 1) % n
	if s[p1] == "L" && spun[p1] == "." 
		spun[p1] = "#"
		kakutei[p1] = "#" 
	elsif s[p1] == "R" && spun[p2] == "." 
		spun[p2] = "#"
		kakutei[p1] = "#" 
	end
end

p kakutei 
p spun

arr = kakutei.split("#")
ans = 0
arr.each do |a|
	next if a.length  == 0
	ans = (ans + (2 ** a.length)) % m998
end

arr.each do |a|
	next if a.length == 0
	hoge = 2 ** (a.length - 1)
	ans = (ans - hoge + m998) % m998
	puts ans
end