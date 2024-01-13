
masu = Array.new 
3.times do |i|
	s = gets.chomp.split.map(&:to_i)
	s.each do |j|
		masu << j  
	end
end

arr = [
	[0, 3, 6],
	[1, 4, 7],
	[2, 5, 8],
	[0, 1, 2],
	[3, 4, 5],
	[6, 7, 8],
	[0, 4, 8],
	[2, 4, 6]
]

cnt = 0
uresi = 0
(0..9).to_a.permutation(9) do |bits|
	cnt += 1
	flag = 1

	arr.each do |ar|
		a = ar[0]
		b = ar[1]
		c = ar[2]

		flag = 0 if masu[a] == masu[b] && bits[a] < bits[c] && bits[b] < bits[c]
		flag = 0 if masu[b] == masu[c] && bits[b] < bits[a] && bits[c] < bits[a]
		flag = 0 if masu[c] == masu[a] && bits[c] < bits[b] && bits[a] < bits[b]		
	end
	uresi += flag 
end


puts cnt 
puts uresi 
puts uresi.to_f / cnt