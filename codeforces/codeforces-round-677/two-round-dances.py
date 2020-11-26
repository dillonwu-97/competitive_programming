
import sys
import math


def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(len(q)):
		n = q[0][0]
		print(math.factorial(n-1) // (n//2))
	

if __name__ == '__main__':
	main()