# Ichihime and Triangle

import sys





def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q)):
		arr = q[i]
		s1 = arr[1]
		s2 = arr[2]
		s3 = arr[2]
		print(s1, s2, s3)

if __name__ == '__main__':
	main()