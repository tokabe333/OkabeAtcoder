n = gets.chomp.to_i
masu = Array.new(n).map{Array.new(n, 0)}
p1 = 0
p2 = 0
n.times do |i|
	s = gets.chomp 
	n.times do |j|
		if s[j] == "P"
			if p1 == 0
				p1 = [i, j]
			else
				p2 = [i, j]
			end
		elsif s[j] == "#"
			masu[i][j] = 1
		end
	end
end	

puts masu.map{|m| m.join("")}.join("\n")
p p1  
p p2
