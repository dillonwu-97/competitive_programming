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

	for i in range(2, len(q),2):
		a = q[i]
		if len(a) % 2 == 1:
			e_a = len(a) // 2 + 1 # even in array 
		else:
			e_a = len(a) // 2
		o_a = len(a) // 2# odd in array

		o = 0
		e = 0
		mismatch = 0
		for i in range(len(a)):
			if a[i]%2 == 0:
				if i % 2 == 1:
					mismatch +=1
				e+=1
			else:
				if i% 2 == 0:
					mismatch +=1
				o+=1

		if mismatch == 0:
			print(0)
		elif o_a != o:
			print(-1)
		else:
			print(mismatch // 2)

		# solve(q[i])

if __name__ == '__main__':
	main()