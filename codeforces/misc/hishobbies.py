#B. Johnny and His Hobbies

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

	for i in range(1, len(q), 2):
		a = q[i+1]
		# solve(q[i])
		m = max(a)
		a2 = []
		sol = -1
		# print("bin", len(bin(m)) - 2)
		m = len(bin(m)) - 2
		m = 2**m
		for i in range(1,m):
			a2 = []
			for j in a:
				# print("i and j is ", i^j)
				temp = i^j
					# print(a2)
					# print("temp is", temp)
					# print("j is", j)
					# print("last is", a[len(a)-1])
				if temp not in a:
					break
					# print('hey')
				elif temp in a2:
					# print("temp" , temp)
					break
				else:
					a2.append(temp)
				# if we make it to the last element
				if j == a[len(a)-1]:
					# print("hi")
					sol = i
			if sol != -1:
				break
		print(sol)



if __name__ == '__main__':
	main()