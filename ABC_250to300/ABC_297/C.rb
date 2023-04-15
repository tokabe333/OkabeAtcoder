h, w = gets.chomp.split.map(&:to_i)
arr = Array.new(h)
h.times do |i|
	arr[i] = gets.chomp.chars 
	(w - 1).times do |j|
		next if arr[i][j] != "T" || arr[i][j + 1] != "T"
		arr[i][j] ="P"
		arr[i][j + 1] = "C"
	end
	puts arr[i].join("")
end

