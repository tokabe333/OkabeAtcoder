require "prime"

def main()
	i = 0
	h = gets.chomp.to_i 
	now = 0
	while now <= h
		now += 2 ** i 
		i += 1
		# puts "#{now} #{i}"
	end
	puts i


	
end


def reads()
	return gets.chomp.split
end

def readints()
	return gets.chomp.split.map(&:to_i)
end

def readfloats()
	return gets.chomp.split.map(&:to_f)
end

main()
