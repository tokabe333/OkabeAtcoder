n = gets.chomp.to_i
r = gets.chomp 
c = gets.chomp 

row = r.chars.map{|rc| rc.ord - "A".ord + 1} 
col =  c.chars.map{|rc| rc.ord - "A".ord + 1} 

def printans(masu)
	masu.length.times do |i|
		s = ""
		masu.length.times do |j|
			if masu[i][j] == 0
				s += "."
			else
				s += ("A".ord + masu[i][j] - 1).chr 
			end
		end
		puts s
	end
end

def check(masu, row, col, n)
	#printans(masu)
	top = Array.new(n, 0)
	# 縦
	n.times do |j|
		abc = Array.new(4, 0)
		n.times do |i|
			top[j] = masu[i][j] if masu[i][j] != 0 && top[j] == 0
			abc[masu[i][j]] += 1
		end
		return false if abc[1] * abc[2] * abc[3] != 1
	end

	
	return top == col 
end

def dfs(masu, depth, row, col, n)
	if depth == n 
		res = check(masu, row, col, n)
		if res == true
			return masu 
		else
			return false 
		end 
	end

	
	top = row[depth]
	ketu = (1..3).select{|a| a != top}
	
	0.upto(n - 3) do |i|
		masu[depth][i] = top 

		2.times do |bc|
			(i + 1).upto(n - 2) do |j|
				masu[depth][j] = ketu[bc[0]]
				(j + 1).upto(n - 1) do |k|
					masu[depth][k] = ketu[(bc[1] + 1) % 2]
					res = dfs(masu, depth + 1, row, col, n)
					masu[depth][k] = 0
				end
				masu[depth][j] = 0
			end
		end
		masu[depth][i] = 0
	end

	return false
end

masu = Array.new(n).map{Array.new(n, 0)}
res = dfs(masu, 0, row, col, n)

p res