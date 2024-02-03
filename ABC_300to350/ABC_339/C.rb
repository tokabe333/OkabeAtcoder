n = gets.chomp.to_i 
arr = gets.chomp.split.map(&:to_i)

ans = 1145141919810931
now = 0
n.times do |i|
	now += arr[i]
	ans = now if now < 0 && ans > now 
end

if ans < 0
	puts (-ans) + now  
else
	puts now
end