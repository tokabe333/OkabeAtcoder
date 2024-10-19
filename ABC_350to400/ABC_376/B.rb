

def main()
	n, q = readints()
	sl = 0
	sr = 1
	ans = 0

	q.times do |i|
		h, t = reads()
		t = t.to_i - 1
		if h == "R"
			next if sr ==  t
			# 右回り
			rnum = 0
			r1 = sr
			while true
				rnum += 1
				r1 = (r1 + 1) % n
				if r1 == sl
					rnum = 10000
					break
				elsif r1 == t
					break
				end
			end

			# 左回り
			lnum = 0
			r2 = sr
			while true
				lnum += 1
				r2 = (r2 - 1 + n) % n
				if r2 == sl
					lnum = 10000
					break
				elsif r2 == t
					break
				end
			end
			if rnum < lnum
				ans += rnum
				sr = r1
			else
				ans += lnum
				sr = r2
			end
			#puts [rnum, lnum].min 
		else
			next if sl == t
			# 右回り
			rnum = 0
			l1 = sl
			while true
				rnum += 1
				l1 = (l1 + 1) % n
				if sr == l1
					rnum = 10000
					break
				elsif l1 == t
					break
				end
			end

			# 左回り
			lnum = 0
			l2 = sl
			while true
				lnum += 1
				l2 = (l2 - 1 + n) % n
				if sr == l2
					lnum = 10000
					break
				elsif l2 == t
					break
				end
			end
			if rnum < lnum
				ans += rnum
				sl = l1
			else
				ans += lnum
				sl = l2
			end
			#puts [rnum, lnum].min 
		end
	end

	puts ans
	
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
