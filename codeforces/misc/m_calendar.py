import sys
from decimal import *

def swap(x, y, a):
	temp = a[x]
	a[x] = a[y]
	a[y] = temp
	return a

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
		r = q[i][1]

		# t = sum(range(1, min(n,r)+1))
		temp = min(n,r)
		t = temp * (temp + 1) // 2
		# for i in range(1, min(n, r) + 1):
		# 	if i == n:
		# 		t +=1
		# 	else:
		# 		t += i
		if n <= r:
			t= t-n +1
		print(t)
		# solve(q[i])

if __name__ == '__main__':
	main()