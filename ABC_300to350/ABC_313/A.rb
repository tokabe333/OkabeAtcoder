n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i)
if arr.length == 1
	puts 0
	exit
end
a0 = arr.shift
ans = [arr.max - a0, 0].max
ans += 1 if a0 <= arr.max 
puts ans