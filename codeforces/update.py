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

	for i in range(1, len(q)):
		#print(q[i])
		startx = q[i][0]
		starty = q[i][1]
		endx = q[i][2]
		endy = q[i][3]
		if (startx == endx and starty == endy):
			print(1)
			continue
		endx -= startx 
		startx -= startx 
		endy -= starty 
		starty -= starty
		current = 0
		left = 1
		above = 1
		right = 0
		below = 0 
		row_index = 0
		column_index = 0
		prev = 0
		#print(startx, starty, endx, endy)
		while(row_index != endx and column_index != endy):
			#print(current, left, above)
			row_index +=1
			column_index +=1
			prev = current
			current = left + above
			if row_index == endx or column_index == endy: # do this to keep the values for left and above
				break
			right = left + current # to the right of current
			below = above + current # to the below of current
			left = below
			above = right
		if row_index == endx and column_index == endy:
			print(current)
		else: # still have to go straight to get to end
			print(current + 1)
			# l_left = 0 # left left
			# if row_index != endx:
			# 	l_left = left - prev
			# 	while (row_index != endx):
			# 		left = l_left + prev
			# 		curr += left

		# solve(q[i])

if __name__ == '__main__':
	main()