# Minimal Square
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
		# print(q[i])
		l = max(q[i])
		w = min(q[i])
		test = (max(w*2, l) )
		# print('test is: ' , test)
		print(test**2)
		# solve(q[i])

if __name__ == '__main__':
	main()