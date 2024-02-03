h, w, n = gets.chomp.split.map(&:to_i)
dist = [[-1, 0], [0, 1], [1, 0], [0, -1]]
d = 0

masu = Array.new(h).map{Array.new(w, ".")}

y = 0
x = 0
n.times do |i|
	#puts "y:#{y} x:#{x}"
	if(masu[y][x] == ".")
		masu[y][x] = "#"
		d = (d + 1) % 4
	else   
		masu[y][x] = "."
		d = (d - 1 + 4) % 4
	end
	
	y = (y + dist[d][0] ) % h
	x = (x + dist[d][1] ) % w
	
	# puts masu.map{|m| m.join("")}.join("\n")
	# puts
end

puts masu.map{|m| m.join("")}.join("\n")
