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

	for i in range(1, len(q),2):
		x = q[i][1]
		a = q[i+1]
		# subset sum? Maybe not
		current = 0
		# ss = [0]
		res = -1
		save_pointer = -1
		flag = 0 # tells us whether or not at some point before this, we had encountered a nondiv subarray
		# forward and backward
		m = -1
		for j in range(2):
			res = -1
			for i in range(len(a)):
				current+= a[i]
				# print("current is ", current)
				if current % x != 0:
					res = i
					# print("res is ", res)
					flag = 0
				else:
					save_pointer = res
					flag = 1
			m = max(m, max(res+1, len(a) - save_pointer - 1) )
			# print("m is", m)
			current = 0
			save_pointer = -1
			flag = 0
			a.reverse()
		if res == -1:
			print(-1)
		else:
			# print(res)
			print(m)

			# ss.append( current)


		




		# # find divisible diff
		# # print(ss)
		# m = -1
		# for i in range(len(ss) - 1, 0, -1):
		# 	for j in range(i-1, -1, -1):
		# 		if (ss[i] - ss[j]) % x != 0:
		# 			res = i - j
		# 			if res > m:
		# 				m = res
		# print(m)


		# solve(q[i])

if __name__ == '__main__':
	main()