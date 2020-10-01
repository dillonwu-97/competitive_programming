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
		i = 0
		j = 1
		while j != len(a):
			# print(a, i, j, a[i], a[j])
			if a[i] > 0 and a[j] < 0:
				if a[i] >= abs(a[j]):
					a[i] += a[j]
					a[j] = 0
				else:
					# print('ok')
					a[j] += a[i]
					a[i] = 0
			if a[i] <= 0:
				i+=1
			if j <= i or a[j] >= 0:
				j+=1
		t = 0
		# print(a)
		for i in range(len(a)):
			if a[i] > 0:
				t+= a[i]
		print(t)


		# solve(q[i])

if __name__ == '__main__':
	main()