n = gets.chomp.to_i 
arr = Array.new(n).map.with_index{|a, i| [i, 0]}
n.times do |i|
	s = gets.chomp
	s.chars.each do |c|
		next if c == "x" || c == "-"
		arr[i][1] += 1
	end
end

 arr
arr = arr.sort{|a, b| [b[1], -b[0]] <=> [a[1], -a[0]]}

puts arr.map{|a| a[0] + 1}.join(" ")