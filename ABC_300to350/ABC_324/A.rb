n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i)

if arr.uniq.length == 1
	puts "Yes"
else
	puts "No"
end

