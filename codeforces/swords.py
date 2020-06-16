import sys
import math

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
		s = q[i][0]
		d = q[i][1]

		count = 0
		while (s > 0 and d > 0):
			if s > d:
				s -=2
				d -=1
			else:
				s -=1
				d -=2
			count +=1
		if s < 0 or d < 0:
			count-=1
		print(count)



		# solve(q[i])

if __name__ == '__main__':
	main()