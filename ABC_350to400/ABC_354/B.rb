require "prime"

def main()
	n = gets.chomp.to_i
	arr = []
	sum = 0
	n.times do |i|
		arr << gets.chomp.split 
		arr[i][1] = arr[i][1].to_i 
		sum += arr[i][1]
	end
	
	arr = arr.sort{|a, b| a[0] <=> b[0]}
	puts arr[sum%n][0]

			
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
