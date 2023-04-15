require "set"

debug = false
n, k, d = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i)

# n個目のarr k個選択した状態 ありえる可能性
kdp = Array.new(n + 1).map{Array.new(k + 1).map{Array.new(d, -1)}}

kdp[0][0][0] = 0

1.upto(n) do |i|
	a = arr[i - 1]

	# i を選ばない場合
	0.upto(k) do |j|
		d.times do |dd|
			kdp[i][j][dd] = kdp[i - 1][j][dd]
		end
	end

	# 選ぶ場合
	1.upto(k) do |j|
		d.times do |dd|
			prev = kdp[i - 1][j - 1][dd]
			next if prev == -1
			num = prev + a 
			ind = num % d

			kdp[i][j][ind] = num if kdp[i][j][ind] < num
		end
	end
end

if debug 
	0.upto(n) do |i|
		p kdp[i]
	end
end

puts kdp[n][k][0] >= 0 ? kdp[n][k][0] : -1