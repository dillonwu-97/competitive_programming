import sys

def swap(x, y, a):
	temp = a[x]
	a[x] = a[y]
	a[y] = temp
	return a

def solve():
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = int(q[i].rstrip().split(' ')[0])
		# q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q)):
		num = q[i]
		if num == 1:
			print(0)
		else:
			total = 0
			while(num != 1):
				if num % 6 == 0:
					total +=1
					num /= 6
					continue
				if num % 3 == 0:
					total +=2
					num /= 3
					continue
				total = -1
				break
			print(total)

		# solve(q[i])

if __name__ == '__main__':
	main()