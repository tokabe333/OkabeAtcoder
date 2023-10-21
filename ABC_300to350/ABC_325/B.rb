n = gets.chomp.to_i

wrr = Array.new(n)
xrr = Array.new(n)
n.times do |i|
	wrr[i], xrr[i] = gets.chomp.split.map(&:to_i)
end

ans = 0
24.times do |i|
	hoge = 0
	n.times do |j|
		x = (xrr[j] + i) % 24
		next if x < 9 || 17 < x 
		hoge += wrr[j]
	end
	ans = hoge if ans < hoge 
end

puts ans
