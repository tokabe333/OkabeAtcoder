require "prime"

def GCD(m, n)
	return 0 if m == 0 || n == 0
	while m != 0 && n != 0
		if m > n then
			m %= n
		else
			n %= m
		end
	end
	return [m, n].max
end

def LCM(m, n)
	return 0 if m == 0 || n == 0
	return m * n / GCD(m, n)
end


n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i)

prime_list = Array.new(n)
n.times do |i|
	prime_list[i] = arr[i].prime_division
end

#最大公約数で同一に...
gcd = GCD(arr[0], arr[1])
1.upto(n - 1) do |i|
	gcd = GCD(arr[i], gcd)
end

#puts "gcd:#{gcd}"
hash = {}
# 最大公約数が1のとき，1以外の要素はすべて2,3の倍数のみで構成されてなければOUT
if gcd == 1
	arr.each do |a|
		next if a == 1
		next if hash.has_key?(a)
		pr = a.prime_division
		hash[a] = pr 
		if pr[-1][0] != 2 && pr[-1][0] != 3
			puts "-1"
			exit 
		end
	end

# 最大公約数が2,3の倍数以外のとき，全てがGCDの倍数でなければOUT
elsif gcd % 2 != 0 && gcd % 3 != 0
	flag = true  
	arr.each do |a|
		if a % gcd != 0
			flag = false 
			break 
		end
	end
	if flag == false 
		puts "-1"
		exit 
	end
end


# puts "gcd #{gcd}"
ans = 0
arr.each do |a|
	hoge = a / gcd
	hoge = hoge.prime_division 

	next if hoge.length == 0
	if hoge[-1][0] != 2 && hoge[-1][0] != 3
		puts "-1"
		exit 
	end
	# puts "hoge:#{hoge}"
	ans += hoge.map{|h| h[1]}.inject(:+) if hoge.length > 0
end
puts ans 

