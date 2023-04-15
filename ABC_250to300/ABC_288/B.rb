n, k = gets.chomp.split.map(&:to_i)
arr = Array.new(n)
n.times do |i|
	arr[i] = gets.chomp 
end 

puts arr.slice(0, k).sort.join("\n")