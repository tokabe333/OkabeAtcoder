require "prime"

def main()

	n, k, x = readints()
	arr = readstrings()

	k.times do |i|
		print(arr[i] + " ")
	end
	print(x.to_s +  " ")
	k.upto(n - 1) do |i|
		print(arr[i] + " ")
	end
	puts
	
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

def readints(c = " ")
	return gets.chomp.split(c).map(&:to_i)
end

def readfloats(c = " ")
	return gets.chomp.split(c).map(&:to_f)
end

def readstrings(c = " ")
	return gets.chomp.split(c)
end

main()
