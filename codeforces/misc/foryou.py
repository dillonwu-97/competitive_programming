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
		# print(q[i])
		a = q[i][0] # vanilla cookies
		b = q[i][1] # chocolate cookies
		n = q[i][2] # guest, type 1
		m = q[i][3] # guest, type 2
		# print(a,b,n,m)
		if m >= min(a, b) and n + m <= a + b:
			print("Yes")
		else:
			print("No")

		# solve(q[i])

if __name__ == '__main__':
	main()