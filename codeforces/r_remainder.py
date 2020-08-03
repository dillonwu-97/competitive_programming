# Required Remainder
import sys

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
		x = q[i][0]
		y = q[i][1]
		n = q[i][2]
		# print(x, y, n)
		temp = n % x
		if y <= temp:
			n -= (temp - y)
		else:
			n = n - temp - (x - y)
		print(n)

		# solve(q[i])

if __name__ == '__main__':
	main()