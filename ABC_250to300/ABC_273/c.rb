n = gets.chomp.to_i 
arr = gets.chomp.split.map(&:to_i)

onazikosuu = Hash.new(0)
lagest = Hash.new
arr.each do |a|
    onazikosuu[a] += 1
    lagest[a] = 0
end 

keys = lagest.keys.sort.reverse
1.upto(lagest.length - 1) do |i|
    lagest[keys[i]] = lagest[keys[i - 1]] + 1
end

keys.each do |k|
    puts onazikosuu[k]
end


(n - keys.length).times do |i|
    puts 0
end