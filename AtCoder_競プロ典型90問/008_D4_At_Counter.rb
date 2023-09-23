n = gets.chomp.to_i
s = gets.chomp
at = "atcoder"
m107 = 10**9 + 7
dp = Array.new(at.length + 1).map{Array.new(n + 1, 0)}
dp[0][0] = 1

(at.length + 1).times do |i|
	n.times do |j|
		dp[i][j + 1] += dp[i][j]
		dp[i][j + 1] -= m107 if dp[i][j + 1] > m107
		next if s[j] != at[i] || i == n
		dp[i + 1][j + 1] += dp[i][j]
		dp[i + 1][j + 1] -= m107 if dp[i][j + 1] > m107
	end
end

puts dp.map{|d| d.join(" ")}.join("\n")
puts dp[at.length][n]