import sys
import math
# from copy import deepcopy

def swap(x, y, a):
	temp = a[x]
	a[x] = a[y]
	a[y] = temp
	return a

def solve(grid):
	# temp = deepcopy(grid)
	rs = 0
	cs = 0
	re = len(grid)-1
	ce = len(grid[0])-1
	ret = 0
	while (cs <= ce):
		rs = 0
		re = len(grid)-1
		while (rs <= re):
			total = list(sorted([grid[rs][cs],grid[rs][ce], grid[re][cs], grid[re][ce]]))
			diff = total[3] + total[2] - total[1] - total[0]
			# total = grid[rs][cs] + grid[rs][ce] + grid[re][cs] + grid[re][ce]
			# avg = (total) / 4
			# avg = round(avg) # <== this was the issue; cant round 
			# print("avg is: ", avg, total, (abs(grid[rs][cs] - avg) + abs(grid[rs][ce] - avg) +\
			#  abs(grid[re][cs] - avg) + abs(grid[re][ce] - avg)))
			# diff = (abs(grid[rs][cs] - avg) + abs(grid[rs][ce] - avg) +\
			#  abs(grid[re][cs] - avg) + abs(grid[re][ce] - avg))
			if (rs == re or cs == ce):
				ret += diff // 2
			else:
				ret += diff
			# temp[rs][cs] = avg
			# temp[rs][ce] = avg
			# temp[re][cs] = avg
			# temp[re][ce] = avg
			rs += 1
			re -= 1
			# print('ret is ', ret)
		cs += 1
		ce -=1
	# print(temp)
	# print('testing ', round(1.4999999), round(1.5), math.ceil(4.3), float(4.3)%1)
	return ret



	

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	i = 1
	while (i < len(q)):
		row_count = q[i][0]
		grid = []
		for j in range(i+1, i + row_count+1):
			grid.append(q[j])
		grid_T = [list(i) for i in zip(*grid)]
		# print(solve(grid_T))
		ret = min( solve(grid), solve(grid_T))
		print(ret)
		i += row_count + 1
	

if __name__ == '__main__':
	main()