import sys

def main():
	# このコードは引数と標準出力を用いたサンプルコードです。
	# このコードは好きなように編集・削除してもらって構いません。
	# ---
	# This is a sample code to use arguments and outputs.
	# Edit and remove this code as you like.

	n = 5
	arr = [1, 2, 3, 4, 5]
	
	s = set()
	for i in range(n):
		a = arr[i]
		if a in s:
			print(i + 1)
			return 0

		s.add(a)
	# end of for

	print(-1)
# end of main


if __name__ == "__main__":
	main()