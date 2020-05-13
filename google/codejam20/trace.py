import sys

def main():
	queries = []
	for line in sys.stdin.readlines():
		queries.append(line)

	for i in range(len(queries)):
		queries[i] = queries[i].rstrip().split(' ')
		queries[i] = [int(x) for x in queries[i]]

	current = 1
	case = 1
	while current < len(queries):
		size = queries[current][0]
		xstart = current + 1
		# square is next 'size' lines
		total = 0
		rowdup = 0
		coldup = 0
		trans = []
		ret = []
		### Finding sum 
		for i in range(size):
			total += queries[xstart + i][i]
			if len(queries[xstart]) != len(set(queries[xstart])):
				rowdup+=1
			trans.append(queries[xstart+i])
		for x in zip(*trans):
			if len(x)!=len(set(list(x))):
				coldup+=1
		print('Case #' + str(case) + ': ' + str(total) + ' ' + str(rowdup) + ' ' + str(coldup))
		### Finding number of rows and columns with duplicates

		current+=size+1
		case+=1
		

if __name__ == '__main__':
	main()