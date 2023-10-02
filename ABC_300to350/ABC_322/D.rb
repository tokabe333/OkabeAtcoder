
poly = Array.new(3).map{Array.new(4)}
3.times do |i|
	4.times do |j|
		poly[i][j] = gets.chomp.chars.map{|c| c == "#" ? 1 : 0}
	end
end


def rotate90(arr)
	brr = arr.transpose.reverse
	miny = 9999
	4.times do |y|
		if brr[y].index{|b| b == 1}
			miny = y  
			break
		end
	end

	minx = 9999
	4.times do |x|
		flag = true
		4.times do |y|
			if brr[y][x] == 1
				minx = x
				flag = false
				break 
			end
		end
		break if flag == false
	end

	# puts "miny:#{miny} minx:#{minx}"
	# puts brr.map{|b| b.join("")}.join("\n")
	# puts

	miny.times do |i|
		brr.shift
		brr << [0, 0, 0, 0]
	end
	minx.times do |j|
		4.times do |i|
			brr[i].shift 
			brr[i] << 0
		end
	end

	return brr
end

# puts poly[0].map{|po| po.join("")}.join("\n")
# poly[0] = poly[0].transpose.reverse
# poly[0] = rotate90(poly[0])
# puts
# puts poly[0].map{|po| po.join("")}.join("\n")
# puts 
# poly[0] = rotate90(poly[0])
# puts poly[0].map{|po| po.join("")}.join("\n")



3.times do |i|
	poly[i] = rotate90(poly[i])
end


def put(poly, masu, y, x)
	flag = true
	4.times do |i|
		4.times do |j|
			next if poly[i][j] == 0
			next if y + 1 <= 3 || x + j <= 3
			next if masu[y + i][x + j] == 0

			flag = false 
			break
		end
	end
	return false if flag == false 

	4.times do |i|
		4.times do |j|
			next if poly[i][j] == 0
			masu[y + i][x + j] = 1
		end
	end
	return true
end


def dfs(poly, depth, masu)
	if depth == 3
		puts "ans!!"
		puts masu.map{|m| m.join("")}.join("\n")
		return true
	end

	# puts "depth:#{depth} masu"
	# puts masu.map{|m| m.join("")}.join("\n")
	# puts

	4.times do |i|
		4.times do |j|
			m = Marshal.load(Marshal.dump(masu))
			r = put(poly[depth], m, i, j)
			# puts "depth:#{depth} r:#{r} i:#{i} j:#{j}"
			next if r == false 
			result = dfs(poly, depth + 1, m)
			return true if result == true
		end
	end

	return false
end

masu = Array.new(4).map{Array.new(4, 0)}
4.times do |i|
	4.times do |j|
		4.times do |k|
			res = dfs(poly, 0, masu)
			puts "i:#{i} j:#{j} k:#{k}"
			if res == true
				puts "Yes"
				exit
			end	
			poly[0] = rotate90(poly[0])
		end
		poly[1] = rotate90(poly[1])
	end
	poly[2] = rotate90(poly[2])
end
puts "No"