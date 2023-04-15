n, k = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i).uniq.sort 

k.times do |i|
	next if arr[i] == i    
	puts i   
	exit 
end
puts k 
