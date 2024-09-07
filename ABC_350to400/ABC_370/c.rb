

def main()
	s = gets.chomp
	t = gets.chomp
	n = s.length

	x = Array.new
	flag = false

	while s != t
		if flag == false
			flag = true
			n.times do |i|
				next if s[i] <= t[i]
				flag = false
				break
			end
		end

		# 小さくするときは前から
		if flag == false
			n.times do |i|
				next if s[i] <= t[i]
				s[i] = t[i]
				x << s + ""
				break
			end

		# 大きくするときは後ろから
		else
			(n - 1).downto(0) do |i|
				next if s[i] >= t[i]
				s[i] = t[i]
				x << s + ""
				break
			end
		end
	end

	puts x.length
	puts x.join("\n")
	
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

