import sys

def solve():
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		# print(q[i])
		q[i] = [int(x) for x in q[i]]


	l = q[1]
	m1 = 0
	m2 = 1
	diff = abs(l[1] - l[0])
	for i in range(1,len(l)):
		if ( abs(l[i] - l[i-1]) < diff):
			diff = abs (l[i] - l[i-1])
			m1 = i
			m2 = i-1

	if abs (l[ len(l) - 1 ] - l[0]) < diff:
		m1 = 0
		m2 = len(l) - 1

	ret = str(m1 + 1) + " " + str(m2 + 1)
	print(ret)


	# l = [(val, index) for index, val in enumerate(q[1])]
	# l = sorted(l)

	# m1 = l[0][1]
	# m2 = l[1][1]
	# diff = l[1][0] - l[0][0]
	# for i in range(1,len(l)):
	# 	temp = l[i][0] - l[i-1][0]
	# 	if (l[i][0] - l[i-1][0] < diff):
	# 		diff = temp
	# 		m1 = l[i][1]
	# 		m2 = l[i-1][1]

	# ret = str(m1+1) + " " + str(m2+1)
	# print(ret)
	# for i in range(len(q[1])):
	# 	print(q[1][i])
		

if __name__ == '__main__':
	main()