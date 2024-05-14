require "prime"

def main()
	n = gets.chomp.to_i
	arr = readints

	1.upto(n-1) do |i|
		if arr[i] > arr[0]
			puts i + 1 
			return 
		end
	end	
	puts -1


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
