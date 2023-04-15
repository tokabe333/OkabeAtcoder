n = gets.chomp.to_i

que = [n]
hash = {}
while que.length > 0
	nn = que.shift 
	next if hash.has_key?(nn) 
	hash[nn] = 0 

	que << (nn / 2)
	que << (nn / 3)
end


keys = hash.keys.sort 
hash[0] = 1
1.upto(keys.length - 1) do |i|
	key = keys[i]
	hash[key] = hash[key / 2] + hash[key / 3]
end

puts hash[n]