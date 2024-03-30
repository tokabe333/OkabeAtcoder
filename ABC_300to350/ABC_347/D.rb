a, b, c = gets.chomp.split.map(&:to_i)

c1num = 0
cc = c
ind1 = Array.new 
ind0 = Array.new 
index = 0
while cc > 0
	aa = cc & 1
	if aa == 1
		c1num += 1
		ind1 << index
	else
		ind0 << index
	end
	cc /= 2
	index += 1
end

60.times do |i|
	hoge = 2 ** i
	next if hoge <= c
	ind0 << i
end

# p ind0 
# p ind1
# puts c.to_s(2)
# puts "ind1.length:#{ind1.length}"

if ((a + b) % 2) != (c1num % 2)
	puts -1
	exit 
end
if c1num > a + b    
	puts -1
	exit
end

ans1 = 0
ans2 = 0

index = 0
loopnum = (a + b - c1num) / 2
while index < loopnum
	if index >= ind0.length 
		puts -1
		exit 
	end

	hoge = 2 ** ind0[index]
	ans1 += hoge  
	ans2 += hoge
	a -= 1
	b -= 1

	index += 1
end

if a < 0 || b < 0
	puts -1
	exit
end

a.times do |i|
	if i >= ind1.length 
		puts -1
		exit
	end
	ans1 += 2 ** ind1[i]
end
b.times do |i|
	if i + a >= ind1.length 
		puts -1
		exit 
	end
	ans2 += 2 ** ind1[i + a]
end

puts "#{ans1} #{ans2}"
# puts ans1.to_s(2)
# puts ans2.to_s(2)
# puts ans1 ^ ans2