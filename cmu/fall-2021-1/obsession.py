import sys

def solve():
	return None


def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	if len(q) == 0: 
		print('OK')
	else:
		for i in range(len(q)):
			q[i] = q[i].rstrip().split(' ')
			# q[i] = [int(x) for x in q[i]]
		s = q[i][0]

		if len(s) == 1 or len(s) == 0:
			print('OK')
		else:
			grid = [[0 for i in range(4*len(s))]for j in range(4*len(s) )]
			ret = 0
			x_s = 2*len(s)
			y_s = 2*len(s)
			# grid[x_s][y_s] = 1
			for i in range(len(s)):
				# print(x_s, y_s)
				grid[x_s][y_s] = 1

				if s[i] == 'U':
					# for i in grid:
					# 	print(i)
					# print('u')
					y_s -= 1
					l = grid[x_s-1][y_s]
					r = grid[x_s+1][y_s]
					u = grid[x_s][y_s-1]
					if r == 1 or u == 1 or l == 1:
						ret = 1
						break
					 
				elif s[i] == 'D':
					# print('d')
					y_s += 1
					r = grid[x_s+1][y_s]
					d = grid[x_s][y_s+1]
					l = grid[x_s-1][y_s]
					if r == 1 or d == 1 or l == 1:
						ret = 1
						break
				elif s[i] == 'R':
					# print('r')
					x_s += 1
					r = grid[x_s+1][y_s]
					d = grid[x_s][y_s+1]
					u = grid[x_s][y_s-1]
					
					if r == 1 or u == 1 or d == 1:
						ret = 1
						break
				elif s[i] == 'L':
					# for i in grid:
					# 	print(i)
					# print('l')
					x_s -= 1
					l = grid[x_s-1][y_s]
					d = grid[x_s][y_s+1]
					u = grid[x_s][y_s-1]
					
					if d == 1 or u == 1 or l == 1:
						ret = 1
						break
				if grid[x_s][y_s] == 1:
					# print(x_s, y_s)
					ret = 1
					break
				
			if ret == 0: 
				print("OK")
			else: 
				print("BUG")



	# grid[0][0] = 1


	# for i in range(1, len(q)):
		# print(q[i])
		# solve(q[i])

if __name__ == '__main__':
	main()