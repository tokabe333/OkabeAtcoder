h, w = gets.chomp.split.map(&:to_i)

sy = -1
sx = -1
masu = Array.new(h)
h.times do |i|
	masu[i] = gets.chomp.split("")
	if masu[i].index("S") != nil 
		sy = i    
		sx = masu[i].index("S")
	end
end


def wfs(masu2, que, h, w)
	while que.length > 0
		y, x = que.shift 
		masu2[y][x] = "z"
		# 上
		ny = y - 1
		nx = x
		if ny >= 0 
			if masu2[ny][nx] == "S"
				puts "Yes"
				exit 
			end
			que << [ny, nx] if masu2[ny][nx] == "."
		end

		# 下
		ny = y + 1 
		nx = x 
		if ny < h  
			if masu2[ny][nx] == "S"
				puts "Yes"
				exit 
			end
			que << [ny, nx] if masu2[ny][nx] == "."
		end

		# 右
		ny = y  
		nx = x + 1
		if nx < w 
			if masu2[ny][nx] == "S"
				puts "Yes"
				exit 
			end
			que << [ny, nx] if masu2[ny][nx] == "."
		end

		# 左
		ny = y  
		nx = x - 1
		if nx >= 0
			if masu2[ny][nx] == "S"
				puts "Yes"
				exit 
			end
			que << [ny, nx] if masu2[ny][nx] == "."
		end
	end
end

#上ルート
if sy - 1 >= 0
	masu2 = masu.map(&:dup)
	masu2[sy - 1][sx] = "z"
	que = []
	que << [sy - 2, sx + 0] if sy - 2 >= 0 && masu2[sy - 2][sx + 0] == "."
	que << [sy - 1, sx - 1] if sx - 1 >= 0 && masu2[sy - 1][sx - 1] == "."
	que << [sy - 1, sx + 1] if sx + 1 < w  && masu2[sy - 1][sx + 1] == "."

	wfs(masu2, que, h, w)
end

# 下ルート
if sy + 1 < h 
	masu2 = masu.map(&:dup)
	masu2[sy + 1][sx] = "z"
	que = []
	que << [sy + 2, sx + 0] if sy + 2 < h   && masu2[sy + 2][sx + 0] == "."
	que << [sy + 1, sx - 1] if sx - 1 >= 0  && masu2[sy + 1][sx - 1] == "."
	que << [sy + 1, sx + 1] if sx + 1 < w   && masu2[sy + 1][sx + 1] == "."
	
	wfs(masu2, que, h, w)
end

# 右ルート
if sx + 1 < w 
	masu2 = masu.map(&:dup)
	masu2[sy][sx + 1] = "z"
	que = []
	que << [sy + 0, sx + 2] if sx + 2 < w   && masu2[sy + 0][sx + 2] == "."
	que << [sy - 1, sx + 1] if sy - 1 >= 0  && masu2[sy - 1][sx + 1] == "."
	que << [sy + 1, sx + 1] if sy + 1 < h   && masu2[sy + 1][sx + 1] == "."

	wfs(masu2, que, h, w)
end

# 左ルート
if sx - 1 >= 0
	masu2 = masu.map(&:dup)
	masu2[sy][sx - 1] = "z"
	que = []
	que << [sy + 0, sx - 2] if sx - 2 >= 0 && masu2[sy + 0][sx - 2] == "."
	que << [sy - 1, sx - 1] if sy - 1 >= 0 && masu2[sy - 1][sx - 1] == "."
	que << [sy + 1, sx - 1] if sy + 1 < h  && masu2[sy + 1][sx - 1] == "."
	
	wfs(masu2, que, h, w)
end	

puts "No"