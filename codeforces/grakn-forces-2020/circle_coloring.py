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

	for i in range(1, len(q), 4):
		n = q[i][0]
		a = q[i+1]
		b = q[i+2]
		c = q[i+3]
		ret = [a[0]]
		for i in range(1,len(a)):
			if i == len(a) - 1:
				if a[i] != ret[i-1] and a[i] != ret[0]:
					ret.append(a[i])
				elif b[i] != ret[i-1] and b[i] != ret[0]:
					ret.append(b[i])
				else:
					ret.append(c[i])	
			else:
				if a[i] != ret[i-1]:
					ret.append(a[i])
				elif b[i] != ret[i-1]:
					ret.append(b[i])
				else:
					ret.append(c[i])
		print(" ".join([str(j) for j in ret]))
		# solve(q[i])

if __name__ == '__main__':
	main()