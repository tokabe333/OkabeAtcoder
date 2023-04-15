n, a, b, p_, q = gets.chomp.split.map(&:to_i)

#各地点iにjターン目に居るパターン数
tarr = Array.new(n + 1).map{Array.new(n - a + 1, 0)}
aarr = Array.new(n + 1).map{Array.new(n - b + 1, 0)}

tarr[a][0] = 1
(n - a).times do |j|
	(n + 1).times do |i|
		1.upto(p_) do |diff|
			if i + diff < n
				tarr[i + diff][j + 1] =(tarr[i + diff][j + 1]+ tarr[i][j]) % 998244353
			else
				tarr[n][j + 1] = (tarr[n][j + 1] +tarr[i][j]) % 998244353
			end
		end
	end
	#tarr[n][j + 1] = tarr[n][j] if j != (n - a - 1)
end

aarr[b][0] = 1
(n - b).times do |j|
	(n + 1).times do |i|
		1.upto(q) do |diff|
			if i + diff < n  
				aarr[i + diff][j + 1] = (aarr[i + diff][j + 1] +aarr[i][j]) % 998244353
			else
				aarr[n][j + 1] = (aarr[n][j + 1] + aarr[i][j]) % 998244353
			end
		end
		#aarr[i][j + 1] = aarr[i][j]
	end
	#aarr[n][j + 1] = aarr[n][j] if j != (n - b - 1)
end

p tarr[-1]
p aarr[-1]

# 高橋くんがかつパターン
twin = 0
truisekiwa = 0
1.upto(n - a - 1) do |j|
	
end