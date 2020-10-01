import sys

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line.rstrip())

	# for i in range(len(q)):
		# q[i] = q[i].rstrip().split(' ')
		# q[i] = [int(x) for x in q[i]]

	for i in range(1,len(q)):
		print(q[i])

if __name__ == '__main__':
	main()