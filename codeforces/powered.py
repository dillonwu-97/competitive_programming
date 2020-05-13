# Powered Addition

import sys
import math

def solve(a):
	diff = []
	for i in range(0,len(a)-1):
		if a[i] > a[i+1]:
			diff.append(a[i] - a[i+1])
	diff.sort()
	if len(diff) == 0:
		return 0
	else:
		dup_count = 0
		# len(diff) - len(list(set(diff)))
		dup_1 = 0
		dup_2 = 0
		large = diff[len(diff) - 1]
		# if largest is nonunique
		if (diff.count(large) > 1):
			dup_1 = diff.count(large)-1
		if (len(diff) > math.log(large, 2)):
			return len(diff)
		# print("dup is " + str(dup_count))
		# print("diff is: " + str(diff))
		log = math.log(diff[ len(diff) - 1 ],2)
		if log.is_integer():
			# return log + dup_count
			return log + 1 + dup_1
		else:
			return math.ceil(log) + 1 + dup_1
	
def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(2, len(q), 2):
		# print(q[i])
		sol = solve(q[i])
		print(int(sol))

if __name__ == '__main__':
	main()

