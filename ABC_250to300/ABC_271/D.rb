n, s = gets.chomp.split.map(&:to_i)
cards = Array.new(n)
n.times do |i|
	cards[i] = gets.chomp.split.map(&:to_i)
end

dp = Array.new(10001).map{Array.new(n, "")}
dp[cards[0][0]][0] = "H"
dp[cards[0][1]][0] = "T"

(n - 1).times do |j|
	h, t = cards[j + 1]
	0.upto(s) do |i|
		next if dp[i][j] == ""
		dp[i + h][j + 1] = dp[i][j] + "H" if i + h <= s  
		dp[i + t][j + 1] = dp[i][j] + "T" if i + t <= s 
	end
end


if dp[s][n - 1] == ""
	puts "No"
else
	puts "Yes"
	puts dp[s][n - 1]
end