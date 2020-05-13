# 640, Div 4
# B. Same Parity Summands
import sys

def solve():
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q)):
		# print(q[i])
		n = q[i][0]
		k = q[i][1]
		# solve(q[i])
		# easy win
		# if n%k == 0:
		# 	print("yes")
		# 	top = str(int(n/k)) + " "
		# 	print(top * k)
		# else if 
		# always try 1 or 2 and see last number
		oddtry = n
		eventry = n
		for i in range(k - 1):
			oddtry -= 1
			eventry -= 2
		if eventry % 2 == 0 and eventry >= 2:
				print("YES")
				print("2 " * (k-1), end = '')
				print(str(eventry))
		elif oddtry % 2 == 1 and oddtry >= 1:
			print("YES")
			print("1 " * (k-1), end = '')
			print(str(oddtry))
		else:
			print ("NO")
			


if __name__ == '__main__':
	main()