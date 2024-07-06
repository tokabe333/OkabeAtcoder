require "prime"

def main()

	a, b, c, d, e, f = readints()
	g, h, i, j, k, l = readints()

	# x軸
	xl = max(a, g)
	xr = min(d, j)
	if xr - xl <= 0
		puts "No"
		return
	end

	# y軸
	yl = max(b, h)
	yr = min(e, k) 
	if yr - yl <= 0
		puts "No"
		return;
	end

	# z軸
	zl = max(c, i)
	zr = min(f, l)
	if zr - zl <= 0
		puts "No"
		return;
	end

	puts "Yes"
	
end

def max(a, b)
	return a > b ? a : b
end

def min(a, b)
	return a < b ? a : b
end

def reads()
	return gets.chomp.split
end

def readint()
	return gets.chomp.to_i
end

def readfloat()
	return gets.chomp.to_f
end

def readints()
	return gets.chomp.split.map(&:to_i)
end

def readfloats()
	return gets.chomp.split.map(&:to_f)
end

main()
