a, m, l, r = gets.chomp.split.map(&:to_i)


l = (l - a)  
r = (r - a) 

ans = r / m - (l - 1) / m
puts ans