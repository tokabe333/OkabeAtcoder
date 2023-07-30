s = gets.chomp
arr = ["ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"]

ans = arr.index{|a| a == s}
if ans != nil
	puts "Yes"
else
	puts "No"
end
