h, w = gets.chomp.split.map(&:to_i)
masu = Array.new(h)
h.times do |i|
	masu[i] = gets.chomp
end
snuke = "snuke"

#(y, x)
diff = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]

h.times do |y|
	w.times do |x|

		diff.each do |d|
			diffy = y + d[0] * 4 
			diffx = x + d[1] * 4
			next if diffy < 0 || diffy >= h || diffx < 0 || diffx >= w 

			flag = true
			5.times do |i|
				yy = y + d[0] * i     
				xx = x + d[1] * i    
				flag = false if masu[yy][xx] != snuke[i]
			end
			
			next if flag == false 
			5.times do |i|
				puts "#{y + d[0] * i + 1} #{x + d[1] * i + 1}"
			end
			exit 
		end
	end
end