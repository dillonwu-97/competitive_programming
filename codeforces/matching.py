# Rotation Matching
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

	# unique displacements
	a = q[1]
	b = q[2]
	indices = {}
	d = []
	for i in range(len(b)):
		indices [b [i]] = i
	for i in range(len(a)):
		if i - indices[a[i]] < 0:
			d.append(len(a) + i - indices[a[i]])
		else:
			d.append(i - indices[a[i]])
	# print(indices)
	# print(d)
	mc, nmc = Counter(d).most_common(1)[0]
	print(nmc)
	# displace = []
	# for i in range(len(a)):
	# 	if a[i] - b[i] < 0:
	# 		displace.append (len(a) + a[i] - b[i])
	# 	else:
	# 		displace.append(a[i] - b[i])
	# most_common,num_most_common = Counter(displace).most_common(1)[0]
	# print(num_most_common)




if __name__ == '__main__':
	main()