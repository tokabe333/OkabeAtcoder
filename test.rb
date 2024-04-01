n = gets.chomp.to_i
arr = [0] + gets.chomp.split.map(&:to_i)
brr = [0] + gets.chomp.split.map(&:to_i)

dp = Array.new(n + 1, 0)
dp[1] = 0
1.upto(n - 1) do |i|
	dp[arr[i]] = dp[i] + 100 if dp[arr[i]] < dp[i] + 100
	dp[brr[i]] = dp[i] + 150 if dp[brr[i]] < dp[i] + 150
end

puts dp[-1]