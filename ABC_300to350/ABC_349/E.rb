masu = Array.new(3)
3.times do |i|
	masu[i] = gets.chomp.split.map(&:to_i)
end

hoge = [
	[-1, 1, -1],
	[1, 1,-1],
	[1, -1, 1],
]

pon = [
	[-1, 1, -1],
	[-1, 1, 1],
	[1, -1, 1],
]

def rotate90(hoge)
	fuga = Array.new(3).map{Array.new(3,0 )}

	3.times do |i|
		3.times do |j|
			fuga[i][j] = hoge[2 - j][i]
		end
	end
	return fuga
end

min = 10 ** 30

4.times do |i|
	num = 0
	num2 = 0
	3.times do |i|
		3.times do |j|
			num += masu[i][j] * hoge[i][j]
			num2 += masu[i][j] * pon[i][j]
		end
	end
	min = num if min > num 
	min = num2 if min > num2

	hoge =rotate90(hoge)
	pon  = rotate90(pon)
end

puts min > 0 ? "Takahashi" : "Aoki"

