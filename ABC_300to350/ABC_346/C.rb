n, k = gets.chomp.split().map(&:to_i)
arr = gets.chomp.split.map(&:to_i)

ksum = (1 + k) * k / 2;
brr = [0]
arr.each do |a|
	next if a > k 
	brr << a 
end

bsum = brr.uniq.inject(:+)

# puts ksum 
# puts bsum 
puts ksum - bsum