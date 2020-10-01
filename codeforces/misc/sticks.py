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
		q[i] = int(q[i].rstrip().split(' ')[0])

	for i in range(1, len(q)):
		n = q[i]
		if n % 2 == 0:
			n /= 2
			print(int(n))
		else:
			n+=1
			n/=2
			print(int(n))
		# solve(q[i])

if __name__ == '__main__':
	main()