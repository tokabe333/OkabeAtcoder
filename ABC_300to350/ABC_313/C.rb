n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i)
ave = arr.inject(:+) / n.to_f
avel = ave.to_i
aveh = ave.ceil

debug = false
puts "ave:#{ave} avel:#{avel} aveh:#{aveh}" if debug

count = 0
tops = 0
bottoms = 0
n.times do |i|
	if arr[i] > ave 
		tops += arr[i] - aveh 
		#arr[i] -= arr[i] - ave
	elsif arr[i] < ave 
		bottoms += avel - arr[i]
	end
	puts "tops:#{tops} bottoms:#{bottoms}" if debug
end
puts "tops:#{tops} bottoms:#{bottoms}" if debug 

puts [tops, bottoms].max