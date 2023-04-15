n, m = gets.chomp.split.map(&:to_i)

# 移動可能方向を出す
squares = {}
i = 1
while i * i <= m 
    squares[i * i] =  true
    i += 1
end

cand = {}
(0..Math.sqrt(m).ceil).each do |i|
    hoge = m - (i * i)
    if squares.has_key?(hoge)
        cand[i] = true 
        cand[Math.sqrt(hoge).to_i] = true
    end 
end
cand = cand.keys

dist = []
cand.each do |c|
    d = Math.sqrt(m - (c * c)).to_i 
    dist << [c, d]
    dist << [-c, -d]
    
    if c != 0 && d != 0
        dist << [-c, d]
        dist << [c, -d]
    end
end
# p squares
# p cand
# p dist

masu = Array.new(n).map{Array.new(n, 0)}
queue = [[0, 0, 0]]
while queue.length > 0
    currenty, currentx, depth = queue.shift
    #puts "cy:#{currenty} cx:#{currentx}"
    if masu[currenty][currentx] != 0 
        next 
    end
    masu[currenty][currentx] = depth + 1
    dist.each do |d|
        x = d[1]
        y = d[0]

        dx = currentx + x 
        dy = currenty + y 

        if 0 <= dx && dx < n && 0 <= dy && dy < n && masu[dy][dx] == 0
            queue << [dy, dx, depth + 1]
        end
    end
end

puts masu.map{|ma| ma.map{|maa| maa - 1}.join(" ")}.join("\n")