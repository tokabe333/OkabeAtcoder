

def main()

	l, r = readints()
	if l + r != 1
		puts "Invalid"
	elsif l == 1
		puts "Yes"
	else
		puts "No"
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
