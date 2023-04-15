import queue
stack = queue.LifoQueue()

n, m = list(map(int, input().split(" ")))
# 例外処理
if m == 0: 
	print(" ".join([str(i + 1) for i in range(n)]))
	exit(0)
# end of if 

arr = set(list(map(int, input().split(" "))))

ans = []
for i in range(1, n + 1):
	# レ点が来るときはいったんスタックに貯めておく
	if i in arr:
		stack.put(i)
	# レ点が無いときはスタックを開放してansにつっこむ
	else:
		ans.append(i)
		while stack.empty() == False:
			ans.append(stack.get())
	# end of ifelse
# end of for

print(" ".join(list(map(str, ans))))

	