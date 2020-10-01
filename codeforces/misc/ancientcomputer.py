# Johnny and the Ancient Computer
 
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
 
	for i in range(1, len(q)):
		# print(q[i])
		a = max(q[i])
		b = min(q[i])
		if (a == b):
			print(0)
			continue
		count = 0
		while (b != a):
			if a%2==0:
				# print(a)
				a//=2
				count+=1
			else:
				# None work
				count = -1
				break
		# print('hi')
		# print(count)
		if count != -1:
			if count % 3 == 0:
				fcount = count // 3
			else:
				fcount = count // 3 + 1
			# fcount = count // 3 #eights
			# count -= 3 * fcount
			# temp = count // 2
			# fcount += temp
			# count -= 2 * temp
			# fcount += count
			count = fcount
 
 
		print(count)
 
 
		# solve(q[i])
 
if __name__ == '__main__':
	main()