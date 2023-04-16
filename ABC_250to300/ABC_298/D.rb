q =  gets.chomp.to_i
arr = [1]
m998 = 998244353
ans = 1
q.times do 
	qi, x = gets.chomp.split.map(&:to_i)
	if qi == 1
		arr << x 
		ans = (ans * 10) % m998 
		ans = (ans + x) % m998
	elsif qi == 2
		ans = (ans + m998 - arr.shift * 10.pow(arr.length, m998)) % m998 
	else
		puts ans
	end
end