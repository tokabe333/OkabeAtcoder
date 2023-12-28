n = gets.chomp.to_i 

arr = [3]
count = 0
abc = [1, 1, 1]
while count <= 333
	3.times do |i|
		abc[i] = abc[i] * 10 + 1
		arr << abc.inject(:+)
		count += 1
	end
	abc = abc.map{|a| a / 10}
	p abc 
	break
end

p arr.length