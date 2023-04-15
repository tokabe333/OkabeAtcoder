n, m = gets.chomp.split.map(&:to_i)
toshi = Array.new(n).map{Array.new}
m.times do 
	a, b = gets.chomp.split.map{|c| c.to_i - 1}
	toshi[a] << b  
	toshi[b] << a
end

n.times do |i|
	puts "#{toshi[i].length} #{toshi[i].map{|t| t + 1}.sort.join(" ")}"
end