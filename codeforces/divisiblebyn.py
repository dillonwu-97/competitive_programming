# 640
# C. K-th Not Divisible by n

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
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q)):
		# print(q[i])
		n = q[i][0]
		k = q[i][1]
		ret = 0
		if n == 2: 
			ret = (k*2 - 1)
		else:
			if (k/(n-1)).is_integer():
				
				ret = k + math.floor(k/(n-1)) - 1
				
			else: 
				ret = (k + math.floor(k/(n-1)))
		if ret % n == 0:
			ret+=1 
		print(ret)

if __name__ == '__main__':
	main()