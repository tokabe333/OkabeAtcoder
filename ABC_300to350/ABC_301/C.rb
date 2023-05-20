require "set"
s = gets.chomp
t = gets.chomp

shash = Hash.new(0)
thash = Hash.new(0)

shash["@"] = 0
thash["@"] = 0
("a".ord.."z".ord).each do |code|
	c = code.chr
	shash[c] = 0
	thash[c] = 0
end

s.chars.each do |c|
	shash[c] += 1
end

t.chars.each do |c|
	thash[c] += 1
end 

atcoder = Set.new(["a", "t", "c", "o", "d", "e", "r"])
("a".ord.."z".ord).each do |code|
	c = code.chr  
	
	next if shash[c] == thash[c]
	if atcoder.include?(c) == false
		puts "No"
		#puts "c:#{c} shash:#{shash[c]} thash:#{thash[c]}"
		exit 
	end
	
	if shash[c] < thash[c]
		shash["@"] -= (thash[c] - shash[c])
		if shash["@"] < 0
			puts "No"
			exit
		end
	elsif thash[c] < shash[c]
		thash["@"] -= (shash[c] - thash[c])
		if thash["@"] < 0
			puts "No"
			exit 
		end
	end
end

puts "Yes"
