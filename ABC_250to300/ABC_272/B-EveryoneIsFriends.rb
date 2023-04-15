n, m = gets.chomp.split.map(&:to_i)
arr = Array.new(m)
m.times do |i|
    arr[i] = gets.chomp.split.map{|mm| mm.to_i - 1}
end 

flags = Array.new(n).map{Array.new(n, false)}
n.times do |i|
    m.times do |j|
        zibun = false 
        (1..arr[j].length - 1).each do |k|
            if arr[j][k] == i   
                zibun = true 
                break 
            end
        end

        if zibun == false
            next
        end
        (1..arr[j].length - 1).each do |k|
            flags[i][arr[j][k]] = true 
        end
    end

    # puts flags.map{|f| f.join(' ')}.join("\n")  
    # puts
end



n.times do |i|
    n.times do |j|
        if flags[i][j] == false
            puts "No"
            exit
        end 
    end
end
puts "Yes"
