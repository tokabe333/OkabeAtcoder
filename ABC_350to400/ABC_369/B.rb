
def main()
	n = gets.chomp.to_i
	left = []
	right = []
	n.times do |i|
		a, s = gets.chomp.split
		a = a.to_i
		if s == "L"
			left << a
		else 
			right << a
		end
	end

	ans = 0
	(left.length - 1).times do |i|
		ans += (left[i] - left[i + 1]).abs
	end
	(right.length - 1).times do |i|
		ans += (right[i] - right[i + 1]).abs
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
