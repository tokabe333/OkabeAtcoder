from collections import deque 

n, m = list(map(lambda x: int(x), input().split(" ")))

graph = [[] for i in range(n)]
dcnt = [0 for i in range(n)]

for i in range(m):
	u, v = list(map(lambda x: int(x) - 1, input().split(" ")))

	graph[u].append(v)
	graph[v].append(u)
# end of for

if n - m - 1 != 0:
	print("No")
	exit(0)

cnt0 = 0
cnt1 = 0 
for i in range(n):
	if len(graph[i]) == 1: cnt0 += 1
	elif len(graph[i]) == 2: cnt1 += 1
	else: print("No"); exit()

flag = set()
que = deque()
que.append(0)
while len(que) > 0:
	c = que.popleft()
	flag.add(c)
	for cc in graph[c]:
		if cc not in flag: que.append(cc)
# end of True 



if (cnt0 == 2 and cnt1 == n -2) and len(flag) == n: print("Yes")
else: print("No")