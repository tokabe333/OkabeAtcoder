n, m = gets.chomp.split.map(&:to_i)

graph1 = Array.new(n).map{Array.new(n, 0)}
graph2 = Array.new(n).map{Array.new(n, 0)}

m.times do |i|
	a, b = gets.chomp.split.map{|x| x.to_i - 1}
	graph1[a][b] = 1
	graph1[b][a] = 1
end

m.times do |i|
	a, b = gets.chomp.split.map{|x| x.to_i - 1}
	graph2[a][b] = 1
	graph2[b][a] = 1
end


bitbit = Array.new(n)
n.times do |i| bitbit[i] = i end 

bitbit.permutation do |bits|
	flag = true 
	n.times do |i|
		n.times do |j|
			next if i == j 
			next if graph1[i][j] == 0

			ii = bits[i]
			jj = bits[j]
			if graph2[ii][jj] == 0
				flag = false 
				break
			end
		end

		break if !flag
	end
	
	if flag 
		puts "Yes"
		exit
	end
end

puts "No"