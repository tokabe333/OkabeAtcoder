n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i)

cut = [0]
arr.each do |a|
	cut = cut.map{|c| c + a}
	cut.unshift(0)
#	p cut
end

cut = cut.map{|c| c % 360}.sort
cut << 360
ans = 0
0.upto(cut.length - 2) do |i|
	ans = [ans, cut[(i + 1) % (n + 2)] - cut[i]].max 
end
#p cut
puts ans