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


cdepth = 0
hash = Hash.new
hash[[sy, sx]] = 1
que = [[sy, sx, 0]]
while que.length > 0
	y, x, depth  = que.shift 
	masu[sy][sx] = depth 
	
	# Hash更新
	if depth > cdepth
		cdepth = depth 
		hash = Hash.new
	end

	# 上
	ny = y - 1
	if ny >= 0 && masu[ny][x] == "."
		if hash.has_key?([ny, x])
			puts "Yes"
			exit 
		end
		hash[[ny, x]] = 1
		que << [ny, x, depth + 1]
	end 

	# 下
	ny = y + 1 
	if ny < h && masu[ny][x] == "."
		if hash.has_key?([ny, x])
			puts "Yes"
			exit 
		end
		hash[[ny, x]] = 1
		que << [ny, x, depth + 1]
	end

	# 右
	nx = x + 1
	if nx < w && masu[y][nx] == "."
		if hash.has_key?([y, nx])
			puts "Yes"
			exit 
		end
		hash[[y, nx]] = 1 
		que << [y, nx, depth + 1]
	end

	# 日s体
	nx = x - 1
	if nx >= 0 && masu[y][nx] == "."
		if hash.has_key?([y, nx])
			puts "Yes"
			exit 
		end
		hash[[y, nx]] = 1 
		que << [y, nx, depth + 1]
	end
end

puts "No"



