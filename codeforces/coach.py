import sys

def solve():
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q), 2):
		# print(q[i])
		a = q[i+1]
		a.sort()
		d = 0 # diff
		m = 9999999 # min
		for i in range(len(a)-1):
			d = abs(a[i] - a[i+1])
			if m > d:
				m = d
		print(m)
		# s1 = 0
		# s2 = 0
		# current = 0
		# for j in a:
		# 	if current <= 0:
		# 		current+=j
		# 		s1+=j
		# 	else:
		# 		current-=j
		# 		s2 +=j
		# 	print(current)

		# solve(q[i])

if __name__ == '__main__':
	main()