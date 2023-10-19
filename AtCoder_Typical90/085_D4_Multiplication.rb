require "set"
k = gets.chomp.to_i 
if k == 1
	puts 1
	exit
end

rtk  = Math.sqrt(k).ceil 

yakusu = Array.new
1.upto(rtk) do |i|
	next if k % i != 0
	yakusu << i    
	yakusu << k / i if k / i != 0
end

yakusu = yakusu.uniq.sort
#p yakusu 
puts yakusu.length

ans = 0
set = Set.new
0.upto(yakusu.length - 2) do |i|
	i.upto(yakusu.length - 1) do |j|
		next if k / yakusu[i] < yakusu[j]
		next if k % (yakusu[i] * yakusu[j]) != 0
		ans += 1 if yakusu[j] <= k / (yakusu[i] * yakusu[j])
	end
end

puts ans