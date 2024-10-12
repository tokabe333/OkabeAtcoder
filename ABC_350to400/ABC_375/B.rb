

def main()
	n = readint()
	px = 0
	py = 0

	ans = 0
	n.times do |i|
		x, y = readints()
		ans += Math.sqrt((px - x)**2 + (py - y)**2)
		px = x
		py = y
	end

	ans += Math.sqrt(px**2 + py**2)

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
