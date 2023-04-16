n, x = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i)

hash = Hash.new(0)
arr.each do |a|
	hash[a] += 1
end

arr.each do |a|
	b = a - x
	if hash.has_key?(b)
		puts "Yes"
		#puts "a:#{a} b:#{b} hash[a]:#{hash[a]} hash[b]:#{hash[b]}"
		exit
	end
end
puts "No"