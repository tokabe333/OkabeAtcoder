import itertools

n, m = list(map(int, input().split(" ")))
sets = list() # 集合のリスト

# S_i を入力
for i in range(m):
	input()
	sets.append(set(list(map(int, input().split(" ")))))
# end of for

ans = 0
for i in range(m):
	# itertoolsを使うことで順列・組み合わせの列挙ができる
	for si in itertools.combinations(sets, i + 1):
		union_set = set()	
		# コンビネーションで選択されたS_iの和集合を作る
		for s in si:
			union_set = union_set.union(s)

			# 1 ~ N まであったらカウントして終わり
			if len(union_set) == n: 
				ans += 1
				break
		#print(f"i:{i} v:{v} set:{uni_set}")
	# end of iterator
# end of for		

print(ans)
