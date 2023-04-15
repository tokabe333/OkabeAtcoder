n = gets.chomp.to_i 
arr = gets.chomp.split.map(&:to_i)
qqqq= gets.chomp.to_i 

q = 0
i = 0 
x = 0
current = -1
hash = Hash.new(0)
qqqq.times do 
	hoge = gets.chomp.split.map(&:to_i)

	if hoge[0] == 1
		current = hoge[1]
		hash = Hash.new(0)

	elsif hoge[0] == 2
		hash[hoge[1]] += hoge[2]
	else
		i = hoge[1]
		if current == -1
			puts arr[i - 1] + hash[i]
		else
			puts hash[i] + current 
		end
	end

end

