masu = Array.new(9)
pone = []
9.times do |i|
	masu[i] = gets.chomp
	9.times do |j|
		if masu[i][j] == "#"
			pone << [i + 1, j + 1]
		end
	end
end


def calc(hoge1, hoge2)
	return (hoge1[0] - hoge2[0])**2 + (hoge1[1] - hoge2[1])**2
end

ans = 0
pone.combination(4) do |pones|
	a, b, c, d = pones
	hash = Hash.new(0)
	hash[calc(a, b)] += 1
	hash[calc(a, c)] += 1
	hash[calc(a, d)] += 1
	hash[calc(b, c)] += 1
	hash[calc(b, d)] += 1
	hash[calc(c, d)] += 1

	next if hash.length != 2
	key1, key2 = hash.keys 
	if (hash[key1] == 4 && hash[key2] == 2)||
		(hash[key1] == 2 && hash[key2] == 4)
		ans += 1
	end
end
puts ans

