# このページを全部コピペ

$BIGMOD = (10**9) + 7

def nCk(n,k)
	b = (1..k).inject(1){|p, c| p * c % $BIGMOD}
	a = (0..k-1).inject(1){|p, c| p * (n - c) % $BIGMOD}
  a * Inv(b) % $BIGMOD
end

def nPk(n,k)
	return Fact(n) / Fact(n-k) % $BIGMOD
end

def Fact(n)
  (1..n).inject(1) { |r, i| (r * i) % $BIGMOD }
end

def Inv(n)
  PowPow(n, $BIGMOD - 2) % $BIGMOD
end

def PowPow(x, n)
  return 1 if n == 0
	return PowPow(x**2  % $BIGMOD, n / 2) if n.even?
  return PowPow(x, n-1) * x  % $BIGMOD 
end


n = gets.chomp.to_i 
arr = gets.chomp.split.map(&:to_i)

shitaketa = 0
(n - 1).downto(1) do |i|
	if arr[i - 1] > arr[i]
		shitaketa = n - i
		break 
	end
end

arr = arr.reverse 
#puts shitaketa 

shitaketanoue = -1
shitaketa.times do |i|
	if arr[i] < arr[shitaketa] && shitaketanoue < arr[i]
		shitaketanoue = arr[i]
	end
end

#puts shitaketanoue

shitaketalist = []
0.upto(shitaketa)  do |i|
	next if arr[i] == shitaketanoue
	shitaketalist << arr[i]
end	

#p shitaketalist
shitaketalist = shitaketalist.sort.reverse 

ans = []
arr.reverse!
(n - shitaketa - 1).times do |i|
	ans << arr[i]
end
ans << shitaketanoue
shitaketalist.each do |s|
	ans << s 
end	

puts ans.join(" ")
