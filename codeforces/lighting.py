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
		m = q[i][1]
		if n * m % 2 == 0:
			print(int( n*m / 2))
		else:
			print (int((n*m-1) / 2 + 1))
		# solve(q[i])

if __name__ == '__main__':
	main()