# Two arrays and swaps
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

	for i in range(1, len(q), 3):
		n = q[i][0]
		k = q[i][1]
		a = q[i+1]
		b = q[i+2]
		
		b.sort(reverse=True)
		a.sort(reverse=True)
		starta = len(a)-1
		startb = 0
		# print(a)
		# print(b)
		while (k!= 0 and a[starta] < b[startb]):
			a[starta] = b[startb]
			starta -=1
			startb+=1
			# print(a)
			k-=1
		print(sum(a))
		

		# solve(q[i])

if __name__ == '__main__':
	main()