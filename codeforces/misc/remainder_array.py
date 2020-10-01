# D. Zero Remainder Array
import sys
from collections import Counter
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
		k = q[i][1]
		a = q[i+1]
		# print(k, a)
		mod = Counter()
		for i in a:
			if i % k != 0:
				mod[k - i % k] +=1
		if len(mod) == 0:
			print(0)
			continue
		val = max(list(mod.values()))
		keys = list(mod.keys())
		max_key = 0
		for i in keys:
			if mod[i] == val and i > max_key:
				max_key = i
		# return mod - 1 number of times + the remainder to get to mod + 1 extra for adding
		print(((mod[max_key]-1) * k) + (max_key % k) + 1)
	
		
		# solve(q[i])

if __name__ == '__main__':
	main()