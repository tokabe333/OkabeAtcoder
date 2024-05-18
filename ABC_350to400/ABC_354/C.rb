require "prime"

def main()
	n = gets.chomp.to_i 
	cards = Array.new 
	n.times do |i|
		cards << readints
		cards[i] << i + 1
	end
	
	cards = cards.sort{|a, b| a[0] <=> b[0]}
	p cards	
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
