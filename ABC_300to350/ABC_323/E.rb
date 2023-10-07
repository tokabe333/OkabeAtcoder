xa, ya, xb, yb, xc, yc = gets.chomp.split.map(&:to_i)

# x, y
mokuhyou = []
if ya == yb && yb == yc 
	if xb < xc 
		mokuhyou = [xb - 1, yb]
	else
		mokuhyou = [xb + 1, yb]
	end

elsif xa == xb && xb == xc 
	if yb < yc 
		mokuhyou = [xb, yb - 1]
	else
		mokuhyou = [xb, yb + 1]
	end

else   
	

end