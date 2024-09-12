def main()
	n, m = readints();
	
	points = Array.new
	n.times do |i|
		line = readints
		s = 0
		m.times do |j|
			s += line[j]
		end
		line << s
		points << line
	end

	points = points.sort{|a, b| a[m] <=> b[m]}
	# puts points.map{|po| po.join(" ")}.join("\n")	

	if n <= 3
		puts 0 
		return 
	end 
	
	ans = 0
	3.upto(n - 1) do |i|
		m.times do |j|
			next if points[i][j] > 3
			ans += 1
			break
		end
	end

	puts ans
end



def reads()
	return gets.chomp.split
end

def readint()
	return gets.chomp.to_i
end

def readfloat()
	return gets.chomp.to_f
end

def readints()
	return gets.chomp.split.map(&:to_i)
end

def readfloats()
	return gets.chomp.split.map(&:to_f)
end

main()
