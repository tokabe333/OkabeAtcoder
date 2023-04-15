n = gets.chomp.to_i
q = gets.chomp.to_i

arr = Hash.new()
brr = Hash.new()

q.times do 
	qi, i, j = gets.chomp.split.map(&:to_i)
	if qi == 1
		if arr.has_key?(j) == true 
			arr[j] << i
		else
			arr[j] = [i]
		end

		if brr.has_key?(i) == true 
			brr[i] << j  
		else
			brr[i] = [j]
		end
	elsif qi == 2
		arr[i].sort!
		puts  arr[i].join(" ")

	else 
		brr[i].uniq!
		brr[i].sort!
		puts  brr[i].join(" ")
	end
end