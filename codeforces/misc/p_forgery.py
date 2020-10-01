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

	for i in range(1, len(q),2):
		a = q[i+1]
		# print(a)
		a = a[::-1]
		a = [str(i) for i in a]
		print(" ".join(a))
		# solve(q[i])

if __name__ == '__main__':
	main()