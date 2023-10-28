from fractions import Fraction

n = int(input())
arr = list(map(int, input().split()))
mod = 998244353

prr = [Fraction(0, 1) for i in range(n + 1)]
prr[0] = Fraction(1, 1)

for i in range(1, n + 1):
	for j in range( i ):
		prr[i] += prr[j]
	prr[i] /= n


#print(prr)
for i in range(n):
	arr[i] *= prr[i + 1]
# print(arr)
# print(sum(arr))

a = sum(arr)
nume = a.numerator
deno = a.denominator
deno = pow(deno, mod - 2, mod)
ans = ((nume * deno) % mod)
print(ans)
#print(f"nume:{nume} deno:{deno}")