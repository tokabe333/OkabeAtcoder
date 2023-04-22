require "set"
r, c = gets.chomp.split.map(&:to_i)
sy, sx = gets.chomp.split.map{|a| a.to_i - 1}
gy, gx = gets.chomp.split.map{|a| a.to_i - 1}

masu = Array.new(r)
r.times do |i|
	masu[i] = gets.chomp.chars 
end

flag = Set.new
que = [[sy, sx, 0]]
while que.length > 0
	cy, cx, depth = que.shift 
	if cy == gy && cx == gx 
		puts depth 
		exit
	end

	next if flag.include?([cy, cx])
	flag << [cy, cx]

	# ã
	que << [cy - 1, cx, depth + 1] if 0 < cy  && masu[cy - 1][cx] == "."
	que << [cy + 1, cx, depth + 1] if cy < r - 1 && masu[cy + 1][cx] == "."
	que << [cy, cx - 1, depth + 1] if 0 < cx && masu[cy][cx - 1] == "."
	que << [cy, cx + 1, depth + 1] if cx < c - 1 && masu[cy][cx + 1] == "."
end



