import sys

def solve():
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)


	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i] if len(x) > 0]

	l = q[0][0]
	for i in range(1,len(q),4):
		a = q[i+1]
		b = q[i+2]
		c = q[i+3]
		n = a[0]

		ret = []
		
		# n^2 solution
		for i in range(1,n+1):
			s = -1 
			for j in range(len(b)):
				temp = abs(b[j] - i) + c[j]
				if s == -1:
					s = temp
				elif temp < s:
					s = temp
			ret.append(s)

		for i in range(len(ret)):
			if i == len(ret) - 1:
				print(str(ret[i]) + " ")
			else:
				print(str(ret[i]) + " ", end='')
		
			



if __name__ == '__main__':
	main()