a = [[1, 2,3], [4,5,6],[7,8,9]]
b = a.map(&:dup)
b[0][0] = 334

a.each do |aa| p aa end 
b.each do |bb| p bb  end