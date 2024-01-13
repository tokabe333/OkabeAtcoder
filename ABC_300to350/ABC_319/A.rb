s = <<"EOS"
tourist 3858
ksun48 3679
Benq 3658
Um_nik 3648
apiad 3638
Stonefeang 3630
ecnerwala 3613
mnbvmar 3555
newbiedmy 3516
semiexp 3481
EOS

ranker = s.split
st = gets.chomp 
ranker.length.times do |i|
	if ranker[i] == st 
		puts ranker[i + 1]
		exit 
	end
end