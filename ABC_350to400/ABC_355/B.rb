require "prime"

def main()
	n, m = readints()
	arr = readints()
	brr = readints()

	crr = arr + brr 
	crr = crr.sort 
	
	hash = HashSet.new(arr)
	p hash
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
