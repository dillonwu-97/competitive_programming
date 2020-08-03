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

	# d = {}
	# for i in str(q[0]):
		# print(i)
	ret = set(q[0])
	if len(ret) % 2 != 0:
		print('CHAT WITH HER!')
	else:
		print('IGNORE HIM!')

	# for i in range(len(q)):
	# 	q[i] = q[i].rstrip().split(' ')
	# 	q[i] = [int(x) for x in q[i]]

	# for i in range(1, len(q)):
	# 	print(q[i])
	# 	# solve(q[i])

if __name__ == '__main__':
	main()