n, t = gets.chomp.split.map(&:to_i)
colors = gets.chomp.split.map(&:to_i)
values = gets.chomp.split.map(&:to_i)

cards = Hash.new 
n.times do |i|
	c = colors[i]
	v = values[i]
	if cards.has_key?(c)
		cards[c] << [v, i]
	else
		cards[c] = [[v, i]]
	end
end

if cards.has_key?(t)
	puts cards[t].sort{|a, b| b <=> a}[0][1] + 1
else
	puts cards[colors[0]].sort{|a, b| b <=> a}[0][1] + 1
end