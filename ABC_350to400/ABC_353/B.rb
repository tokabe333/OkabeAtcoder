require "prime"

def main()
	n, k = readints()
	arr = readints()

	ans = 0
	i = 0
	while i < n 
		sum = 0
		while i < n && k - sum >= arr[i]
			sum += arr[i]
			i += 1			
			
		end
		ans += 1
	end

	puts ans


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
