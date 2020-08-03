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

	for i in range(1, len(q), 2):
		a = q[i+1]
		start = len(a) - 2
		size = (len(a)-2) // 2 - 1
		e = []
		o = []

		# goal: make gcd = 2
		# keep track of indices
		for i in range(len(a)):
			if a[i] % 2 == 0:
				e.append(i)
			else:
				o.append(i)
		
		# make the number of odd numbers even
		if len(o) == 0:
			e = e[:-2]
		elif len(o) % 2 == 1:
			o = o[:-1]
			e = e[:-1]
		else:
			o = o[:-2]

		etrack = 0
		otrack = 0
		# print(e)
		# print(o)
		while(start > size):
			if len(e) > etrack:
				print(e[ etrack] + 1, " ", e[etrack + 1] + 1)
				# print('numbers printed ', a[e[etrack]], ' ', a[e[etrack + 1]])
				etrack+=2
			elif len(o) > otrack:
				print(o [otrack] + 1, " ", o [otrack + 1] + 1) 
				# print('numbers printed ', a[o[otrack]], ' ', a[o[otrack + 1]])
				otrack +=2
			start -=1
		

		

if __name__ == '__main__':
	main()