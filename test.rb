n, k = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i)


def check(t, k, arr)
	s = 0
	arr.each do |a|
		s += t / a 
	end
	return s >= k
end

l = 0
r = 10 ** 9 + 1
mid = 0
ans = {}
while (l - r).abs > 1
	mid = (l + r) / 2
	ret = check(mid, k, arr)
	ans[mid] = ret 
	r = mid if ret 
	l = mid if !ret 
end

min = 1145141919810931364364
ans.each do |k, v|
	next if !v 
	min = k if k < min
end
puts min