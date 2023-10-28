require "set"
n, x, y = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i)

hori = Array.new
vert = Array.new
n.times do |i|
	if i % 2 == 0 
		hori << arr[i]
	else
		vert << arr[i]
	end
end

prev = Hash.new
prev[0] = ""

hori.each do |a|
	nex = Hash.new 
	prev.keys.each do |key|
		v = prev[key]
	end
end

p prev
