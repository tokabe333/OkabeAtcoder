require "prime"

def main()
	n, m = readints()
	arr = readints()

	n.times do |i|
		xrr = readints()
		m.times do |j|
			arr[j] -= xrr[j]
		end
	end
	
	arr.each do |a|
		if a > 0 
			puts "No"
			exit
		end
	end
	puts "Yes"
	
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
