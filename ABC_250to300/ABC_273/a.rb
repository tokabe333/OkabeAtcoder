n = gets.chomp.to_i

if n == 0
    puts 1
else
    su = 1
    n.downto(1) do |i|
        su *= i 
    end
    puts su 
end 