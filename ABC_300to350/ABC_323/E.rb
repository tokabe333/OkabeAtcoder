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
	# 右上
	if xb < xc && yb < yc 
		mokuhyou = [[xb - 1, yb], [xb, yb - 1]]
	# 右下
	elsif xb < xc && yc < yb  
		mokuhyou = [[xb - 1, yb], [xb, yb + 1]]
	# 左下
	elsif xc < xb && yc < yb 
		mokuhyou = [[xb + 1, yb], [xb, yb + 1]]
	# 右上
	elsif xc < xb && yb < yc 
		mokuhyou = [[xb + 1, yb], [xb, yb - 1]]
	end
end

if mokuhyou.length > 1
	d1 = (mokuhyou[0][0] - xa).abs + (mokuhyou[0][1] - ya).abs 
	d2 = (mokuhyou[1][0] - xa).abs + (mokuhyou[])
end