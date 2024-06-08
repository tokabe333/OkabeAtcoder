n = gets.chomp.to_i

carp = Array.new(n + 1)
carp[0] = [["#"]]

1.upto(n) do |k|
	arr = Array.new(3 ** k).map{Array.new(3 ** k)}
	k31 = 3 ** (k - 1)
	3.times do |i|
		3.times do |j|
			if i == 1 && j == 1
				k31.times do |y|
					k31.times do |x|
						arr[i]
					end
				end

			end
		end
	end
end