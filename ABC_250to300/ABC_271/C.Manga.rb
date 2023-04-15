n = gets.chomp.to_i

manga = Hash.new(2)
arr = gets.chomp.split.map(&:to_i)
arr.each do |a|
	manga[a] = 1
end

i = 1
while n >= 0 && manga
	n -= manga[i]
	if n < 0 
		puts i - 1 
		exit
	end
	i += 1
end