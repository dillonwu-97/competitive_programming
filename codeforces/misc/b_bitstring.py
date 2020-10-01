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

	for i in range(len(q),2):
		q[i] = q[i].rstrip().split(' ')
		q[i+1] = q[i+1].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q), 2):
		k = q[i]
		b = q[i+1]
		print(k, b)
		

		# solve(q[i])

if __name__ == '__main__':
	main()