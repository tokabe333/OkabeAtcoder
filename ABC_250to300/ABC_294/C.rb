n, m = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i)
brr  = gets.chomp.split.map(&:to_i)
crr = arr + brr 
crr.sort!

ind = 0
ans = []
crr.length.times do |i|
	next if arr[ind] != crr[i]
	ans << [i + 1]
	ind += 1
	break if ind >= arr.length 
end
puts ans.join(" ")


ind = 0
ans = []
crr.length.times do |i|
	next if brr[ind] != crr[i]
	ans << [i + 1]
	ind += 1
	break if ind >= brr.length 
end
puts ans.join(" ")