n, m = gets.chomp.split.map(&:to_i)
s = gets.chomp 
arr = s.split("0")

ans = 0
arr.each do |a|
	rogo = a.count("2")
	muzi = a.length - m
	ans = rogo if ans < rogo 
	ans = muzi if ans < muzi 
end
puts ans