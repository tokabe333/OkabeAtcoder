n = gets.chomp.to_i
arr = Array.new(n)
henkou = Array.new(n)
giseki_all = 0
n.times do |i|
	arr[i] = gets.chomp.split.map(&:to_i)

	ninzu = ((arr[i][1] - arr[i][0]) / 2.0).ceil
	ninzu = 0 if ninzu < 0 
	giseki = arr[i][2]
	henkou[i] = [ninzu, giseki]

	giseki_all += arr[i][2]
end

max_value = (10 ** 9) + 114514 

dp = Array.new(giseki_all + 1).map{Array.new(n + 1, max_value)}
dp[0][0]  = 0
n.times do |j|
	0.upto(giseki_all) do |i|
		next if dp[i][j] == max_value
		# 横移動
		dp[i][j + 1] = dp[i][j] if dp[i][j] < dp[i][j + 1]

		# 斜め移動
		ninzu, giseki = henkou[j]
		next if i + giseki > giseki_all 
		dp[i + giseki][j + 1] = dp[i][j] + ninzu if dp[i][j] < dp[i + giseki][j + 1]
	end
end

ans = 1145141919810931
((giseki_all + 1) / 2).upto(giseki_all) do |i|
	ans = dp[i][-1] if ans > dp[i][-1]
end

puts ans

