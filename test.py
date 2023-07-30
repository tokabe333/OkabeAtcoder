import sys
import requests


def main():
	# このコードは引数と標準出力を用いたサンプルコードです。
	# このコードは好きなように編集・削除してもらって構いません。
	# ---
	# This is a sample code to use arguments and outputs.
	# Edit and remove this code as you like.

	token = "5198d3f1-b93e-40f3-a248-3a69d77ab7b0"
	# token = "52baaa19-5056-418b-ac6d-0a0372e6b740"
	url = "http://challenge-server.code-check.io/api/kidnapper"

	p = {"token" : token}
	res = requests.get(url + "/start", params = p)
	print(res)
	while "put_the_bag" not in res.json():
		print(res.json())
		goto = res.json()["goto"]
		p = {"token" : token, "to" : "hoge"}
		res = requests.get(url + "/deliver", params = p)
	
	print(res.json())
	print(goto)



if __name__ == "__main__":
	main()