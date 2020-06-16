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

	for i in range(2, len(q),3):
		a = q[i]
		indices = q[i+1]
		# print(a)
		# print(indices)
		if a == sorted(a):
			print ("Yes")
		elif len(set(indices)) == 1:
			print ("No")
		else:
			print("Yes")
		# solve(q[i])

if __name__ == '__main__':
	main()