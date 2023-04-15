# 実装が下手なのでTLEする

MOD = 998244353
n, m, k, s, t, x = gets.chomp.split.map(&:to_i)
s -= 1
t -= 1
x -= 1
graph = Array.new(n).map{Array.new}
m.times do 
	u, v = gets.chomp.split.map{|hoge| hoge.to_i - 1}
	graph[u] << v 
	graph[v] << u;
end

# 移動距離，ノード番号，偶奇 → パターン数
dp = Array.new(k + 1).map{Array.new(n).map{Array.new(2, 0)}}
dp[0][s][0] = 1

1.upto(k) do |i|
	n.times do |j|
		
		# j == x ではない
		if j != x
			# 連結成分の和
			graph[j].each do |g|
				dp[i][j][0] += dp[i - 1][g][0]
				dp[i][j][1] += dp[i - 1][g][1]
			end

			dp[i][j][0] = dp[i][j][0] % MOD 
			dp[i][j][1] = dp[i][j][1] % MOD
		# j == x のときは交差
		else 
			graph[j].each do |g|
				dp[i][j][0] += dp[i - 1][g][1]
				dp[i][j][1] += dp[i - 1][g][0]
			end
		end

		dp[i][j][0] = dp[i][j][0] % MOD 
		dp[i][j][1] = dp[i][j][1] % MOD
	end
end

puts dp[-1][t][0] % MOD