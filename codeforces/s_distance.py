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
		if i % 2 == 1:
			q[i] = q[i].rstrip().split(' ')
			q[i] = [int(x) for x in q[i]]
		else:
			q[i] = q[i].rstrip()

	for i in range(1, len(q),2):
		# z = q[i][0]
		d = q[i][1] + 1
		s = q[i+1]
		z = len(s)
		# print(z, d, s)
		# solve(q[i])

		loc = [-1] # all locations
		for i in range(len(s)):
			if s[i] == '1':
				loc.append(i)
		if len(loc) == 1 and z == d-1:
			print(1)
			continue
		loc.append(z)
		res = 0
		for i in range(1,len(loc)):
			# print(loc[i-1], loc[i], d)
			# print('sum is ', loc[i] - loc[i-1] - 1)
			if loc[i] == loc[i-1]:
				continue
			else:
				if loc[i-1] == -1 and loc[i] == z:
					res+=1
					res += (loc[i] - loc[i-1] - 1 - 1) // d
				elif loc[i-1] != -1 and loc[i] != z:
					temp = (loc[i] - loc[i-1] - 1)
					# print("temp is ", temp, 2 * (d-1), d)
					if temp > 2 * (d-1):
						temp -= (d-1) # subtract for padding
						# print("temp is ", temp, 2 * (d-1), d)
						res = res + temp // (d)
				else:
					res = res + (loc[i] - loc[i-1] - 1) // d
		print(res)

















if __name__ == '__main__':
	main()