import sys
import collections

table = collections.Counter()

# ptask stands for person's task
def isok(ptask, subarr):
	res = True
	if len(ptask) == 0: 
		return res
	for i in ptask:
		if i[1] > subarr[0] and i[0] < subarr[1] or i[0] < subarr[1] and i[1] > subarr[0]:
			res = False
	return res

def solve(C, J, arr, sol):
	if len(arr) == 0:
		return sol
	else:
		temp = None
		if isok(C, arr[0]) == True:
			C.append(arr[0])
			sol+='C'
			temp = solve(C, J, arr[1:], sol)
		if temp == False:
			sol = sol[:-1]
			C.pop()
		if (temp == None or temp == False) and isok(J, arr[0]) == True:
			J.append(arr[0])
			sol+='J'
			temp = solve(C, J, arr[1:], sol)
			if temp == False:
				sol = sol[:-1]
				J.pop()
		if temp == None or temp == False:
			return False
		else:
			sol = temp

	return sol

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	current = 1
	case = 1
	while current < len(q):
		C = []
		J = []
		size = q[current][0]
		arr = []
		for j in range(size):
			arr.append(q[current + j+1])
		# print(arr)
		sol = solve(C, J, arr, '')
		if sol == None or sol == False:
			sol = 'IMPOSSIBLE'
		print('Case #' + str(case) + ': ' + sol)
		current+= size+1
		case+=1

# Case #1: CJC
# Case #2: IMPOSSIBLE
# Case #3: JCCJJ
# Case #4: CC

if __name__ == '__main__':
	main()