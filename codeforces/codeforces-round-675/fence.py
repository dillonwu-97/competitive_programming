import sys
import random

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
		a = q[i][0]
		b = q[i][1]
		c = q[i][2]
		temp = [a,b,c]
		temp.sort()
		if (temp[2] > temp[1] + temp[0]):
			print( temp[2] - temp[1] - temp[0] + 1)
		else:
			print(1)
		# solve(q[i])

if __name__ == '__main__':
	main()