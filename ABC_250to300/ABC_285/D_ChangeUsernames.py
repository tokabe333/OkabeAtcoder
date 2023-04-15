n = int(input())
shash = dict()
tset = set()
for i in range(n):
	s, t = input().split(" ")
	shash[s] = t
	tset.add(t) 

# 探索済み保持
flag = set()

for s in shash.keys():
	if s in flag: continue 

	# 1回の順路記憶用
	root = set() 

	# 閉路ならアウト
	while True:
		#print(f"s:{s} t:{t}")
		t = shash[s]
		if t in root:
			print("No")
			exit(0)
		# end of if 
		root.add(s)
		flag.add(s)
		s = t  
		if s not in shash: break
	# end of while
# end of for

print("Yes")