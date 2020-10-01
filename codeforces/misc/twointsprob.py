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
		a = max(q[i][0],q[i][1])
		b = min(q[i][0],q[i][1])
		x = a - b
		if x % 10 == 0:
			print(x // 10)
		else:
			print (x // 10 + 1)

		# solve(q[i])

if __name__ == '__main__':
	main()