import sys

def main():
	queries = []
	for line in sys.stdin.readlines():
		queries.append(line)

	for i in range(len(queries)):
		queries[i] = queries[i].rstrip()

	direction = ''
	result = ''
	case = 1
	for i in range (1, len(queries)):
		if i%2 == 0:
			direction = str(queries[i])
		for j in direction:
			if j == 'S': result+= 'E'
			else: result+='S'
		if i%2 == 0: 
			print("Case #" + str(case) + ': ' + result) 
			case+=1
		result = ''




if __name__ == '__main__':
	main()