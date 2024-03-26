n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i).sort.reverse


if arr[0] + arr[1] > 0
	puts "Yes"
else
	puts "No"
end