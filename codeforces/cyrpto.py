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
		l = q[i][0]
		r = q[i][1]
		m = q[i][2]

		# Not fast enough
		# for i in range(l, r+1):
		diff = r-l
		diff2= l-r
		for i in range(r, l-1, -1):
			temp = m%i
			if temp <= diff and temp != m:
				print(i, l+ temp, l)
				break
			elif temp-i >= diff2 and temp-i != m:
				print(i, l, l + i - temp)
				break
		# print((m + c - b )// a)
				

		# solve(q[i])

if __name__ == '__main__':
	main()