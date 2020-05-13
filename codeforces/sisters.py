# Candies and Two Sisters

import sys

# def solve:
# 	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line.rstrip())

	# for i in range(len(q)):
		# q[i] = q[i].rstrip().split(' ')
		# q[i] = [int(x) for x in q[i]]
# 3
# 0
# 0
# 1
# 999999999
# 381621773
	for i in range(1, len(q)):
		if int(q[i])%2 == 0:
			# print('q' + str(q[i]))
			print(int(q[i])//2 - 1)
		else:
			print(int(q[i])//2)

		# solve(q[i])

if __name__ == '__main__':
	main()