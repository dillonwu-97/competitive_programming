# Buying Shovels
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
		sol = 0
		inverted = 0
		if k == 1:
			sol = n
		elif k >= n:
			sol = 1
		else:
			i = 1
			while (i*i <= n):
				# print(i)
				if n % i == 0:
					# need to save inverted value because some numbers wont be reached since this is sqrt method
					if (i <= k):
						inverted = n / i
					if n/i <= k:
						sol = i
						# print(sol)
						break
				i+=1
			if sol == 0:
				sol = inverted
		print(int(sol))
		# solve(q[i])

if __name__ == '__main__':
	main()