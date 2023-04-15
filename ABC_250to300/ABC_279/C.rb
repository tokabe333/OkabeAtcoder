h, w = gets.chomp.split.map(&:to_i)
arr = Array.new(w).map{Array.new(h)}
brr = Array.new(w).map{Array.new(h)}

h.times do |i|
	hoge = gets.chomp.split("")
	w.times do |j|
		t = hoge[j] == "#" ? 1 : 0
		arr[j][i] = t 
	end
end
h.times do |i|
	hoge = gets.chomp.split("")
	w.times do |j|
		t = hoge[j] == "#" ? 1 : 0
		brr[j][i] = t 
	end
end


hash1 = Hash.new(0)
hash2 = Hash.new(0)

w.times do |i|
	hash1[arr[i]] += 1
	hash2[brr[i]] += 1
end

if hash1 == hash2
	puts "Yes"
else
	puts "No"
end
