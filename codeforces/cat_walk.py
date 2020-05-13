import sys


def main():
	queries = []
	for line in sys.stdin.readlines():
		queries.append(line)

	for i in range(len(queries)):
		queries[i] = queries[i].rstrip()

	sol = []
	for i in range(1,len(queries),2):
		move = list(queries[i].split())
		box = list(queries[i+1].split())
		move = [int(j) for j in move]
		box = [int(j) for j in box]
		move[0] = move[0] * -1 # convert left and down to negative numbers
		move[2] = move[2] * -1
		# print(move)
		# print(box)
		flag = 'yes' # 1 means ok
		# if (move[0] + move[1] > -1*box[2] + box[4]) or\
		# (move[0] < -1*box[2]+ and move[1] > box[4]) or\
		# (move[2] + move[3] > -1*box[3] + box[5]) or\
		# (move[2] < -1*box[3] and move[3] > box[5]):
		startx = box[0] 
		starty=box[1]
		x1=box[2]
		y1=box[3]
		x2=box[4]
		y2=box[5]
		a=move[0]
		b=move[1]
		c=move[2]
		d=move[3]
		if not (startx + a >= x1 and startx + a + b <= x2):
			if not (startx + b <= x2 and startx + b + a >= x1):
				sol.append('no')
				continue
		if not (starty + c >= y1 and startx + c + d <= y2):
			if not (starty + c <= y2 and starty + c + d >= y1):
				sol.append('no')
				continue
		sol.append('yes')

	for i in sol:
		print(i)





if __name__ == '__main__':
	main()