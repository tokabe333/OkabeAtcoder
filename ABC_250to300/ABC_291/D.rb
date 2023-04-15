
MOD = 998244353 
n = gets.chomp.to_i
arr = Array.new(n)
n.times do |i|
	arr[i] = gets.chomp.split.map(&:to_i)
end

dp = Array.new(n).map{Array.new(2, 0)}
dp[0][0] = 1
dp[0][1] = 1
1.upto(n - 1) do |i|
	2.times do |j|
		dp[i][j] = (dp[i][j] + dp[i - 1][0]) % MOD if arr[i][j] != arr[i - 1][0] 
		dp[i][j] = (dp[i][j] + dp[i - 1][1]) % MOD if arr[i][j] != arr[i - 1][1]
	end
end

puts (dp[n - 1][0] + dp[n - 1][1]) % MOD