n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i)

map = Hash.new
if n == 1
	map[arr[0]] = [-1, -1]
else 
	n.times do |i|
		if i == 0
			map[arr[i]] = [-1, arr[i + 1]]
		elsif i == n - 1
			map[arr[i]] = [arr[i - 1], -1]
		else
			map[arr[i]] = [arr[i - 1], arr[i + 1]]
		end
	end
end

def printmap(map)
	start = -1
	map.each do |k, v|
		if v[0] == -1
			start = k 
			break
		end
	end

	while start != -1
		print start, " "
		start = map[start][1]
	end
end

q = gets.chomp.to_i 
q.times do 
	hoge, x, y = gets.chomp.split.map(&:to_i) 
	if hoge == 1
		# けつの場合
		if map[x][1] == -1 
			map[x][1] = y 
			map[y] = [x, -1]
		else
			tugi = map[x][1]
			map[x][1] = y
			map[y] = [x, tugi]
			map[tugi][0] = y
		end
	else
		map[map[x][0]][1] = map[x][1] if map[x][0] != -1
		map[map[x][1]][0] = map[x][0] if map[x][1] != -1
		map.delete(x)
	end

end

printmap(map)