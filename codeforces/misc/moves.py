# Board Moves

import sys

def solve():
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line.rstrip())

	# for i in range(len(q)):
	# 	q[i] = q[i].rstrip().split(' ')
	# 	q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q)):
		k = int(q[i]) // 2
		# print(k)
		# solve(q[i])
		total = 0
		i = 0
		while (i != k):
			total += (i+1)**2 * 8 
			i+=1
		print(total)
			

if __name__ == '__main__':
	main()