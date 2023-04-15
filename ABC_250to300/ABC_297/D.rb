a, b = gets.chomp.split.map(&:to_i)

cnt = 0
while a != b   
	#puts "a:#{a} b:#{b} cnt:#{cnt}"
	break if a == 0 || b == 0
	a, b = b, a if a < b    
	aa = a % b
	cnt += (a - aa) / b
	cnt -= 1 if aa == 0
	a = aa 
end
#puts "a:#{a} b:#{b} cnt:#{cnt}"
puts cnt
