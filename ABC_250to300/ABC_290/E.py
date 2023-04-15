import sys
sys.setrecursionlimit(10**6)

n = int(input())
arr = list(map(int, input().split(" ")))
se = dict()

def saiki(size, left, right):
	ret = [0] * 3
	ret[1] = arr[left]
	ret[2] = arr[right]

	if size == 1:
		#print(f"left:{left} right:{right} ret:{' '.join(list(map(str, ret)))}")
		ret[0] = 0
		return ret
	# end of if

	ans1 = [0] * 3
	ans2 = [0] * 3
	if size == 2 or (left, right - 1) not in se:
		se[(left, right - 1)] = True
		ans1 = saiki(size - 1, left, right - 1)
	# end of if

	if size == 2 or (left + 1, right) not in se:
		se[(left + 1, right)] = True
		ans2 = saiki(size - 1, left + 1, right)
	# end of if

	ret[0] = ans1[0] + ans2[0]
	if ans1[1] != ans2[2]:
		#print("hoge",ans1[1], ans2[2])
		ret[0] += 1

	#print(f"size:{size} left:{left} right:{right} ans:{' '.join(list(map(str, ret)))}")

	return ret 
# end of func

se[(0, n -1)] = True
ans = saiki(n, 0, n - 1)
print(ans[0])

