require "prime"

def main()
	n, l, r = readints()
	arr = (1..n).to_a


	ans = []
	0.upto(l - 2) do |i|
		ans << arr[i]
	end

	(r-1).downto(l-1) do |i|
		ans << arr[i]
	end

	r.upto(n - 1) do |i|
		ans << arr[i]
	end

	puts ans.join(" ")


	
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
