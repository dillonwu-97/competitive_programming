import sys

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

	k = q[0][1]

	# combining the ones that we can combine
	# get rid of the ones where both people dont like reading
	both = [] # keeps track of books both people like
	only_left = [] # only left person likes
	only_right = [] # only right person likes
	for i in range(1,len(q)):
		if q[i][1] == 1 and q[i][2] == 1:
			both.append(q[i][0])
		elif q[i][1] == 1 and q[i][2] == 0:
			only_left.append(q[i][0])
		elif q[i][1] == 0 and q[i][2] == 1:
			only_right.append(q[i][0])
	# print(both)
	# print(only_left)
	# print(only_right)
	only_left.sort()
	only_right.sort()
	for i in range(min(len(only_left), len(only_right))):
		both.append(only_left[i] + only_right[i])
	both.sort()
	if len(both) < k:
		print(-1)
	else:
		# print(both)
		print(sum(both[:k]))





	# print(k, q)

if __name__ == '__main__':
	main()