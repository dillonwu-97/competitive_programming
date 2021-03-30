# Note: cannot use gmpy2
import sys
import math
 
def solve():
	return None
 
def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)
 
	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		# q[i] = [int(x) for x in q[i]]
 
	for i in range(1, len(q)):
		# print(q[i])
		n = int(q[i][0])
		x = q[i][0]
		flag = 0
		while (flag == 0):
			s = 0
			for i in x:
				s += int(i)
			if (math.gcd(n, s) > 1):
				print(n)
				flag = 1
			else:
				n += 1
				x = str(n)
		
 
if __name__ == '__main__':
	main()