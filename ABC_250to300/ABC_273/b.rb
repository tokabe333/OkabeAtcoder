x, k = gets.chomp.split.map(&:to_i)

1.upto(k) do |i|
    x = x.round(-i)
   # puts x
end

puts x