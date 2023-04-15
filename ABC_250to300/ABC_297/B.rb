s = gets.chomp.chars
ss = s.reverse
flag1 = true
if s.index{|c| c == "B"} % 2 != ss.index{|c| c == "B"} % 2
	flag1 = false
end

flag2 = true
if (s.index{|c| c == "R"} < s.index{|c| c == "K"} &&  ss.index{|c| c == "R"} < ss.index{|c| c == "K"} ) == false
	flag2 = false
end

# p flag1, flag2
puts flag1 && flag2 ? "Yes" : "No"