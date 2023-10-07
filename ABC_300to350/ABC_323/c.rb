n, m = gets.chomp.split.map(&:to_i)
point = gets.chomp.split.map(&:to_i)

player = Array.new(n, 0)
n.times do |i| 
	player[i] = i + 1
end
failed = Array.new(n).map{Array.new}

n.times do |i|
	s = gets.chomp 
	m.times do |j|
		if s[j] == "x"
			failed[i] << point[j]
		else
			player[i] += point[j]
		end
	end
end

max = 0
n.times do |i|
	max = player[i] if max < player[i]
end

n.times do |i|
	if max <= player[i]
		puts 0
	else
		failed[i] = failed[i].sort.reverse
		ans = 0
		failed[i].length.times do |j|
			player[i] += failed[i][j]
			ans += 1
			if max <= player[i]
				break
			end
		end
		puts ans

	end
end
