#Sorted Adjacent Differences

import sys

def solve(arr):
	# print("start")
	sol = []
	if len(arr) % 2 == 1:
		i = len(arr)//2
		j = len(arr)//2
	else:
		i = len(arr)//2 - 1
		j = len(arr)//2
	while (i!= -1 and j!= len(arr)):
		# print('i is ' + str(i))
		# print('j is ' + str(j))
		# print(arr[i])
		# print(arr[j])
		if (i == j):
			sol.append(arr[i])
		else:
			sol.append(arr[i])
			sol.append(arr[j])
		i-=1
		j+=1
	return (sol)

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]
	
	for i in range(2, len(q), 2):
		q[i].sort()
		# print(q[i])
		sol = solve(q[i])
		# print(sol)
		print(' '.join(map(str, sol)))

if __name__ == '__main__':
	main()