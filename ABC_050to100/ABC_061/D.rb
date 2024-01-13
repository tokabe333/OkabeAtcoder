n, m = gets.chomp.split.map(&:to_i)

inf = 1145141919810931

edges = Array.new(m)
m.times do |i|
	edges[i] = gets.chomp.split.map(&:to_i)
	edges[i][0] -= 1
	edges[i][1] -= 1
	edges[i][2] *= -1
end

dist = Array.new(n, inf)
dist[0] = 0
n.times do |i|
	m.times do |j|
		from = edges[j][0]
		to = edges[j][1]
		cost = edges[j][2]

		next if dist[from] == inf 
		next if dist[to] <= dist[from] + cost 
		dist[to] = dist[from] + cost 
		if i == n - 1
			puts "inf"
			exit 
		end
	end
end	

puts dist[-1] * (-1)