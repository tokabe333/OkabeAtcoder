n = int(input())
arr = list(map(int, input().split(" ")))
m = int(input())
b = set(list(map(int, input().split(" "))))
x = int(input())

dp = [False for i in range(x + 1)]
dp[0] = True

for i in range(1, x + 1):
	if i in b: continue 
	for a in arr:
		if i - a < 0: continue 
		if dp[i - a] == True:
			dp[i] = True 
			break 
	# end of for
# end of while

print("Yes") if dp[x] else print("No")