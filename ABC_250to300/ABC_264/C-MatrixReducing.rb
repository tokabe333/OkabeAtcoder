h1, w1 = gets.chomp.split.map(&:to_i)
mat1 = Array.new(h1)
h1.times do |i|
	mat1[i] = gets.chomp.split.map(&:to_i)
end 

h2, w2 = gets.chomp.split.map(&:to_i)
mat2 = Array.new(h2)
h2.times do |i|
	mat2[i] = gets.chomp.split.map(&:to_i)
end

rcand = (0..h1-1).to_a.combination(h2)
ccand = (0..w1-1).to_a.combination(w2)


arr = Array.new(h2).map{Array.new(w2)}
rcand.each do |ra|
	ccand.each do |ca|

		ra.length.times do |i|
			ca.length.times do |j|
				arr[i][j] = mat1[ra[i]][ca[j]]
			end
		end

		if arr == mat2 
			puts "Yes"
			exit
		end

	end
end

puts "No"

