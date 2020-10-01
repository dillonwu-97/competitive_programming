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
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q)):
		x = q[i][0]
		y = q[i][1]
		k = q[i][2]
		# solve(q[i])
		sticks_needed = k + y * k
		if (sticks_needed-1) % (x-1) == 0:
			sticks_buy = (sticks_needed-1) //(x-1)
		else:
			sticks_buy = (sticks_needed-1) //(x-1) + 1
		# print(sticks_buy, sticks_needed)

		# ans: trade of coals + trade to get req sticks
		print (k + sticks_buy)

if __name__ == '__main__':
	main()