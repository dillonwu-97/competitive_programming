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

	for i in range(1, len(q), 2):
		a = q[i+1]
		# solve(q[i])
		for i in range(len(a)):
			if i % 2 == 0 and a[i] < 0:
				a[i] *= -1
			elif i % 2 == 1 and a[i] > 0:
				a[i] *= -1
		print(" ".join([str(i) for i in a]))
		# check




if __name__ == '__main__':
	main()