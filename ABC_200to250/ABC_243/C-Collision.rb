
n = gets.chomp.to_i 
xrr = Array.new(n)
yrr = Array.new(n)
n.times do |i|
	xrr[i], yrr[i] = gets.chomp.split.map(&:to_i)
end
str = gets.chomp 

people = Hash.new
n.times do |i|
	dist = str[i] == "L" ? 0 : 1
	if people.has_key?(yrr[i]) 
		people[yrr[i]][dist] << xrr[i]
	else
		people[yrr[i]] = Array.new(2).map{Array.new}
		people[yrr[i]][dist] << xrr[i]
	end
end	

people.keys.each do |key|
	lefts, rights = people[key]
	next if lefts.length == 0 || rights.length == 0 
	if lefts.max > rights.min 
		puts "Yes"
		exit 
	end
end
puts "No"