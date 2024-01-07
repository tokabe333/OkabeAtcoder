h = gets.chomp.to_i 
w = 5
masu = Array.new(h)
h.times do |i|
	masu[i] = gets.chomp.chars.map{|m| m == "." ? 0 : m.to_i}
end

while true
	kousin = false 
	dst = masu.map(&:dup)
	
	h.times do |i|
		w.times do |j|
			next if masu[i][j] == 0
			ue = i - 1 < 0
			ue = true if ue == false && masu[i - 1][j] == masu[i][j]

			sita = h <= i + 1
			sita = true if sita == false && masu[i + 1][j] == masu[i][j]

			hidari = j - 1 < 0 
			hidari = true if hidari == false && masu[i][j - 1] == masu[i][j]

			migi = w <= j + 1 
			migi = true if migi == false && masu[i][j + 1] == masu[i][j]

			next if (ue && sita && migi && hidari) == false 
			kousin = true
			
			dst[i][j] = 0 
			dst[i - 1][j] = 0 if 0 <= i - 1 && ue == true
			dst[i + 1][j] = 0 if i + 1 < h && sita  == true 
			dst[i][j - 1] = 0 if 0 <= j - 1 && hidari == true 
			dst[i][j + 1] = 0 if j + 1 < w && migi == true 		
		end
	end

	# ‰º‚É—Ž‚Æ‚·
	while true 
		otiru = false 
		(h - 1).times do |i|
			w.times do |j|
				next if dst[i + 1][j] != 0 || dst[i][j] == 0
				dst[i + 1][j] = dst[i][j]
				dst[i][j] = 0
				otiru = true 
			end
		end
		# dst.each do |d| p d end 
		# puts otiru 
		# puts 
		break if otiru == false 
	end

	#masu = dst.map(&:dup)
	masu = dst
	# masu.each do |m| p m end 
	# puts kousin 
	# puts 
	break if kousin == false 
end

puts masu.map{|m| m.map{|mm| mm == 0 ? "." : mm.to_i}.join("")}.join("\n")