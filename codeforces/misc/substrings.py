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
		q[i] = q[i].rstrip()
		# q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q)):
		s = q[i]
		# print(s)
		res = s[0]
		for i in range(1,len(s)-1):
			if i % 2 ==1:
				res+= s[i]
			else:
				continue
		res += s[-1]
		print(res)
		# print(q[i])
		# solve(q[i])

if __name__ == '__main__':
	main()