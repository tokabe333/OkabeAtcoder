bigmod = 998244353 
a, b, c, d, e, f = gets.chomp.split.map(&:to_i)



puts (a * b * c - d * e * f) % bigmod