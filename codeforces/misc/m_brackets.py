# C. Move Brackets
import sys

def swap(x, y, a):
	temp = a[x]
	a[x] = a[y]
	a[y] = temp
	return a

def solve(s, p):
	curr = 0
	ans = 0
	for i in range(len(s)):
		if s[i] == p:
			curr +=1 
		else:
			curr -=1
		if curr < 0:
			ans +=1
			curr +=1
	return ans
		

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')[0]
		# q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q), 2):

		s = q[i+1]
		r = s[::-1]
		ans = solve(s, '(')
		ans = min(ans, solve(r, ')'))
		print(ans)


		# solve(q[i])

if __name__ == '__main__':
	main()