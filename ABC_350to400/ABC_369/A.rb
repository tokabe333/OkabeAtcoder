
def main()
	a, b= gets.chomp.split.map(&:to_i)
	if a > b 
		a, b = b, a
	end

	if a == b
		puts 1
		exit
	end

	if (b - a) % 2 == 0
		puts 3
	else
		puts 2
	end

	
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
