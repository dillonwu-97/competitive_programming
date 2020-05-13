# code jam 2019, foregone solution problem
import sys

def solve(n):

	# Dictionary of values
	breakdown = {0: [0,0], 1: [1, 0], 2: [1,1], 3: [2,1],\
	4: [2,2], 5:[3,2], 6:[3,3], 7:[5,2], 8:[6,2], 9:[7,2]}
	x = 0
	y = 0
	n = str(n)
	length = len(n)
	for i in range(length):
		x += breakdown[int(n[i])][0] * 10 ** (length - i - 1)
		y += breakdown[int(n[i])][1] * 10 ** (length - i - 1)

	return [x, y]

def main():
	queries = []
	for line in sys.stdin.readlines():
		queries.append(line)

	for i in range(len(queries)):
		queries[i] = queries[i].rstrip()

	solution = [0,0]
	for i in range(1,int(queries[0]) + 1):
		solution = solve(queries[i])
		print ('Case #' + str(i) + ': ' + str(solution[0]) + ' ' + str(solution[1]))

if __name__ == '__main__':
	main()