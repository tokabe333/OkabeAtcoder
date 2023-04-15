n, m = list(map(lambda x: int(x), input().split(" ")))

slist = []
tset = set()

for i in range(n):
	slist.append(input()[-3:])

for i in range(m):
	tset.add(input())

cnt = 0 
for s in slist:
	if s in tset: cnt+= 1


print(cnt)