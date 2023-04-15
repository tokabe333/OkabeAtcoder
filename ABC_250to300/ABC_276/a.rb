s = gets.chomp.reverse
if s.index("a") == nil
	puts -1
else
	puts s.length - s.index("a")
end
