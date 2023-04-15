$a, $b = gets.chomp.split.map(&:to_f)

def f(x)
	return $a / Math.sqrt(x + 1) + $b * x
end

l = 0
r = $a / $b
threshold = 2

while (r - l).abs > threshold
	l2 = (2 * l + r) / 3
	r2 = (l + 2 * r) / 3
	
	f1 = f(l2)
	f2 = f(r2)
	if f1 < f2 
		r = r2
	else
		l = l2
	end
end

mini = 10 ** 20
l.to_i.upto(r.to_i) do |i|
	ff  = f(i)
	mini = ff if mini > ff 
end

puts mini