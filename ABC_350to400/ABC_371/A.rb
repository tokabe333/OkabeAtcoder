

def main()
	ab, ac, bc = gets.chomp.split
	
	if ab == "<" && ac == "<"
		if bc == "<"
			puts "B"
		else
			puts "C"
		end
	elsif ab == ">" && bc == "<"
		if ac == "<"
			puts "A"
		else
			puts "C"
		end
	elsif ac == ">" && bc == ">"
		if ab == "<"
			puts "A"
		else
			puts "B"
		end
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
