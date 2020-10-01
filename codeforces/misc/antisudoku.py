# Anti Sudoku

import sys

def solve():
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip()
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q)):
		# print("old row " + str(q[i]))
		# temp = q[i].split()
		# print(temp)
		for j in range(len(q[i])):
			# print(j)
			if q[i][j] == 3:
				q[i][j] = 1
		q[i] = [str(x) for x in q[i]]
		print("".join(q[i]))


if __name__ == '__main__':
	main()