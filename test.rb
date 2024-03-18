s = "aacfdafreqrewquiopbuipdsanmhdsjafsadfyuiyvcxzovuyczxoiufa"
hash = Hash.new(0)
s.length.times do |i|
	s.length.times do |j|
		t = s + ""
		c = t[i]
		t[i] = t[j]
		t[j] = c
		hash[t] += 1
	end
end

p hash.keys
p hash.keys.length