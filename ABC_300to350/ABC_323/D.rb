n = gets.chomp.to_i 
hash = Hash.new(0)
que = Array.new 

n.times do |i|
	s, c = gets.chomp.split.map(&:to_i)
	hash[s] = c   
	que << s
end

que = que.sort 
while que.length > 0
	key = que.shift 
	
end

p hash

hash.keys.each do |key|
	next if hash[key] == 0
	big = hash[key] / 2
	hash[key] -= big * 2
	hash[key * 2] += big    
end	

p hash
sum = 0
hash.keys.each do |key|
	sum += hash[key]
end
p sum

