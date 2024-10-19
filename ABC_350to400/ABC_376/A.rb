

def main()
	n, c = readints()
	arr = readints()
	ans = 1
	prev = arr[0]
	1.upto(n - 1) do |i|
		if arr[i] - prev >= c
			ans += 1
			prev = arr[i]
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
