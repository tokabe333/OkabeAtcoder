require "prime"

n = gets.chomp.to_i
n.times do 
	a = gets.chomp.to_i
	prr = Prime.prime_division(a)
	num = 0
	prr.each do |pr|
		num += pr[1]
		break if num > 3
	end
	puts num == 3 ? "Yes" : "No"
end