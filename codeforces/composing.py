#Two Teams Composing

import sys
from collections import Counter

def solve(arr):
	count = Counter()
	uni = []
	non = []
	maxi = -1
	mval = -1
	for i in arr:
		if i in count:
			non.append(i)
		else:
			uni.append(i)
		count[i]+=1
		if count[i] > maxi:
			maxi = count[i]
			mval = i
	# print('uni' + str(uni))
	# print('non' + str(non))
	if len(non) == 0 and len(uni) > 1:
		return 1
	if len(uni) == 0 and len(non) > 1:
		return 1
	# if len(non) > 0 and non[0] in uni:
	# 	return min(len(non), len(uni)) + 1
	# else:
	# uniqify
	non = [i for i in non if i == mval]
	if len(non) > 0 and non[0] in uni and len(uni) > len(non):
		non.append(uni.remove(non[0]))
	return min(len(non), len(uni))


		

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q), 2):
		# print(q[i])
		# print(q[i+1])
		sol = solve(q[i+1])
		print(sol)


if __name__ == '__main__':
	main()