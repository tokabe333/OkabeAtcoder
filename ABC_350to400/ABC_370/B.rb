

def main()
	n = readint();
	elems = []
	n.times do |i|
		elems << gets.chomp.split.map{|x| x.to_i - 1}
	end

	i = 0
	n.times do |j|
		if i < j
			i = elems[j][i]
		else
			i = elems[i][j]
		end
	end

	puts i + 1

	
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
