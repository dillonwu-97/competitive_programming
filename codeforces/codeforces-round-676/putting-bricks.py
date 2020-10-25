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

	i = 1
	while i < len(q):
		n = int(q[i][0])
		matrix = [q[i+j+1][0] for j in range(n)]
		c = 0
		flag1 = 0
		flag2 = 0
		# print(matrix)
		# start/end cases: [0,0],[1,0],[0,1],[1,1]
		if matrix[0][1] == '0' and matrix[1][0] == '0':
			if matrix[n-1][n-2] == '0':
				flag1 = 1
				c += 1
			if matrix[n-2][n-1] == '0':
				flag2 = 1
				c+=1
			print(c)
			if flag1 == 1: print(n, n-1)
			if flag2 == 1: print(n-1, n)
		if matrix[0][1] == '1' and matrix[1][0] == '1':
			if matrix[n-1][n-2] == '1':
				flag1 = 1
				c += 1
			if matrix[n-2][n-1] == '1':
				flag2 = 1
				c+=1
			print(c)
			if flag1 == 1: print(n, n-1)
			if flag2 == 1: print(n-1, n)
		if matrix[0][1] == '1' and matrix[1][0] == '0':
			# check ends and flip the one with less
			if matrix[n-1][n-2] == '0':
				flag1 = 1
				c += 1
			if matrix[n-2][n-1] == '0':
				flag2 = 1
				c+=1
			if c == 0: # means both '1' so flip the 1->0
				print(1)
				print(1, 2)
			elif c == 2: # means both '0' so flip the 0-> 1
				print(1)
				print(2, 1)
			else: # means 1
				print(2)
				print(1,2)
				if flag1 == 1: print(n, n-1)
				if flag2 == 1: print(n-1, n)
		if matrix[0][1] == '0' and matrix[1][0] == '1':
			# check ends and flip the one with less
			if matrix[n-1][n-2] == '0':
				flag1 = 1
				c += 1
			if matrix[n-2][n-1] == '0':
				flag2 = 1
				c+=1
			if c == 0: # means both '1' so flip the 1->0
				print(1)
				print(2, 1)
			elif c == 2: # means both '0' so flip the 0-> 1
				print(1)
				print(1, 2)
			else: # means 1
				print(2)
				print(2,1)
				if flag1 == 1: print(n, n-1)
				if flag2 == 1: print(n-1, n)
		
		

		i+=n + 1
		# solve(q[i])

if __name__ == '__main__':
	main()