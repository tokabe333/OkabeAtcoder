hash = {"R" => 0, "G"=>1, "B"=>2}
srr = gets.chomp.split.map{|s| hash[s]}
trr = gets.chomp.split.map{|t| hash[t]}

cnt = 0;
if srr[0] != trr[0]
	ind = srr.index{|s| s == trr[0]}
	srr[0], srr[ind] = srr[ind], srr[0]
	cnt += 1
end

if srr[1] != trr[1]
	cnt += 1
end

puts cnt % 2 == 0 ? "Yes" : "No"