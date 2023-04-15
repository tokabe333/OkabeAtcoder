n, dx, dy = gets.chomp.split.map(&:to_i)
arr = gets.chomp.split.map(&:to_i)

# true → horizontal false → vertical
memo = {}
queue = Array.new
queue << [0, arr[0], 0, true]

while queue.length > 0 do 
	depth, x, y, is_horizontal = queue.shift 
	next if memo.has_key?([depth, x, y]) == true 
	depth += 1

	#puts "depth:#{depth} x:#{x} y:#{y}"

	if depth >= arr.length 
		if x == dx && y == dy 
			puts "Yes"
			exit
		end 
		next 
	end 

	dist = arr[depth]
	# ue 
	if is_horizontal == true 
		ue = [depth, x, y + dist]
		if memo.has_key?(ue) == false		
			memo[ue] = 0
			ue << false 
			queue << ue 
		end
	end

	# sita
	if is_horizontal == true 
		sita = [depth, x, y - dist]
		if memo.has_key?(sita) == false		
			memo[sita] = 0
			sita << false 
			queue << sita
		end
	end

	# hidari
	if is_horizontal == false
		hidari = [depth, x - dist, y]
		if memo.has_key?(hidari) == false 
			memo[hidari] = 0
			hidari << true 
			queue << hidari
		end
	end

	# migi 
	if is_horizontal == false
		migi = [depth, x + dist, y]
		if memo.has_key?(migi) == false 
			memo[migi] = 0
			migi << true 
			queue << migi
		end
	end
end

puts "No"


