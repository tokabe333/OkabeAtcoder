n, a, b = gets.chomp.split.map(&:to_i)
a -= 1
b -= 1
p, q, r, s = gets.chomp.split.map{|hoge| hoge.to_i - 1}

masu = Array.new(q - p + 1).map{"." * (s - r + 1)}

masu.length.times do |i|
	masu[i].length.times do |j|
		# ‰E‰º
		dx = j + r - b   
		dy = i + p - a  

		flag = false 
		# ‰Eã
		masu[i][j] = "#" if dy.abs == dx.abs 

	end
end

masu.length.times do |i|
	puts masu[i]
end