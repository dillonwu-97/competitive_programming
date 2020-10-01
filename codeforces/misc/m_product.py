import sys

def swap(x, y, a):
	temp = a[x]
	a[x] = a[y]
	a[y] = temp
	return a



def one(a, b, x, y, n):
	temp_y = b - y
	if temp_y < n:
		b = y
		n -= temp_y
		if a - x < n:
			a = x
		else:
			a -= n
	else:
		b -= n
	return a * b

def two(a,b,x,y,n):
	temp_x = a - x
	if temp_x < n:
		a = x
		n -= temp_x
		if b - y < n:
			b = y
		else:
			b -= n
	else:
		a -= n
	return a * b

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q)):
		# print(q[i])
		a, b, x, y, n = q[i][0], q[i][1], q[i][2], q[i][3], q[i][4]
		# always subtract from smaller


		
		if a != b:
			print(min(one(a,b,x,y,n), two(a,b,x,y,n)))
		else:
			x, y = min(x, y), max(x,y)
			# print("x is: ", x, y)
			temp_x = a - x
			if temp_x < n:
				a = x
				n-= temp_x
				# print('n is: ',a, x, n)
				if b - y < n:
					b = y
				else:
					# print("hi ", b - y, n, y)
					b -=n
					# b = max(b - n, y)
			else:
				a -= n
			# print('bef ', a, b)
			print(a * b)

		# print(a * b)

		# solve(q[i])

if __name__ == '__main__':
	main()