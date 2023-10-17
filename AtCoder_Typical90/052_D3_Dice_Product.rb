n = gets.chomp.to_i 
MOD = 10 ** 9 + 7
dice = Array.new(6).map{Array.new(n)}

n.times do |j|
	arr = gets.chomp.split.map(&:to_i)
	6.times do |i|
		dice[i][j] = arr[i]
	end
end

#puts dice.map{|d| d.join(" ")}.join("\n")

dp = Array.new(6).map{Array.new(n, 0)}
6.times do |i|
	dp[i][0] = dice[i][0]
end

1.upto(n - 1) do |j|
	6.times do |i|
		6.times do |k|
			dp[i][j] += dice[i][j] * dp[k][j - 1];
		end
		#dp[i][j] %= MOD 
	end
end

#puts dp.map{|d| d.join(" ")}.join("\n")

ans = 0
6.times do |i|
	ans += dp[i][n - 1]
end
puts ans % MOD