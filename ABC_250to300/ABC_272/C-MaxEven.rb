n = gets.chomp.to_i 
arr = gets.chomp.split.map(&:to_i)

odd = Array.new 
even = Array.new

arr.each do |a|
    if a.even? == true
        even << a 
    else
        odd << a 
    end
end

odd.sort!
even.sort!

if odd.length <= 1 && even.length <= 1 
    puts -1
    exit 
end 

if odd.length <= 1 
    puts even[-1] + even[-2]
    exit 
end

if even.length <= 1
    puts odd[-1] + odd[-2]
    exit
end

omax = odd[-1] + odd[-2]
emax = even[-1] + even[-2]
puts [omax, emax].max
