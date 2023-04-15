
def BinarySearch(arr, n)
	l = 0
	r = arr.length
	prev = -1
	while l < r 
		mid = (l + r) / 2
		return mid if mid == prev 
		if arr[mid] == n 
			return mid 
		elsif n < arr[mid] 	
			r = mid 
		else
			l = mid 
		end
		prev= mid
	end
	return -1
end

def Min(a, b)
    return a < b ? a : b    
end
def Max(a, b)
    return a > b ? a : b    
end

h, w, y, x = gets.chomp.split.map(&:to_i)
n = gets.chomp.to_i
kabe_r = {}
kabe_c = {}
n.times do |i|
    r, c = gets.chomp.split.map(&:to_i)
    if kabe_r.has_key?(r)
        kabe_r[r] << c   
    else 
        kabe_r[r] = [0, 0, c, x + 1, x + 1]
    end 

    if kabe_c.has_key?(c)
        kabe_c[c] << r 
    else   
        kabe_c[c] = [0, 0, r, y + 1, y + 1]
    end
end


#　hashのソート
kabe_c.keys.each do |k|
    kabe_c[k].sort! 
end

kabe_r.keys.each do |k|
    kabe_r[k].sort!
end

p kabe_r 
p kabe_c

q = gets.chomp.to_i 
q.times do |i|
    d, l = gets.chomp.split 
    l = l.to_i 

    if d == "U"
        kabe = kabe_c[x]
        mid = BinarySearch(kabe, y)
        if kabe[mid] == y
            y = Max(kabe[mid - 1], Max(y - l, 0))
        elsif kabe[mid] > y 
            y = Max(kabe[mid - 1], Max(y - l, 0))
        else 
            y = Max(kabe[mid], Max(y - l, 0))
        end 
    elsif d == "D"
        kabe = kabe_c[x]
        mid = BinarySearch(kabe, y)
        if kabe[mid] == y 
            y = kabe[mid + 1]
        elsif kabe[mid] > y 
            y = kabe[mid]
        else   
            y = kabe[mid + 1]
        end 
    elsif d == "L"
        kabe = kabe_c[y] 
        mid = BinarySearch(kabe, x)
        if kabe[mid] == x 
            x = kabe[mid - 1]
        elsif kabe[mid] > x 
            x = kabe[mid - 1]
        else  
            x = kabe[mid]
        end
    elsif d == "R"
        kabe = kabe_c[y]
        mid = BinarySearch(kabe, x)
        if kabe[mid] == x
            x = kabe[mid + 1]
        elsif kabe[mid] > x 
            x = kabe[mid]
        else
            x = kabe[mid + 1]
        end
    end
    puts "#{y} #{x}"
end

