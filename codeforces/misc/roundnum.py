# Codeforces 640 D4
# Sum of Round Numbers

import sys

def solve():
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')[0]

	for i in range(1, len(q)):
		num = q[i]
		nums = []
		count = 0
		zeros = ""
		for j in range(len(q[i])-1, -1, -1):
			if q[i][j] != '0':
				zeros += ("0" * count)
				nums.append (str(q[i][j]) + zeros)
			count+=1
			zeros = ""
		print(len(nums))
		print(*nums)
		# start = 1;
		# d = len(str(q[i]))
		# nums = []
		# for i in range(d):
		# 	nums.append()

if __name__ == '__main__':
	main()