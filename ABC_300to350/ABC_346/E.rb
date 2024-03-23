h, w, m = gets.chomp.split.map(&:to_i)

tate = {}
yoko = {}
arr = Array.new(m)
m.times do |i|
	arr[i] = gets.chomp.split.map(&:to_i)
	arr[i][1]-=1
	if(arr[i][0] == 1)
		tate[arr[i][1]] = [i, arr[i][2]]
	else
		yoko[arr[i][1]] = [i, arr[i][2]]
	end
end

masu = Array.new(h).map{Array.new(w, 0)}
inf = 1145141919810
h.times do |i|
	w.times do |j|
		t = tate.has_key?(i)
		y = yoko.has_key?(j)
		if(t && y )
			a, b = tate[i]
			c, d = yoko[j]
			masu[i][j] = a < c ? d : b;
		elsif(t && !y)
			masu[i][j] = tate[i][1]
		elsif(!t && y)
			masu[i][j] = yoko[j][1]
		else
			masu[i][j]  =0
		end
	end
end

# puts masu.map{|m| m.join(" ")}.join("\n")

ans = Hash.new(0)
h.times do |i|
	w.times do |j|
		c = masu[i][j]
		ans[c] += 1
	end
end

puts ans.length
ans.keys.sort.each do |key|
	puts "#{key} #{ans[key]}"
end