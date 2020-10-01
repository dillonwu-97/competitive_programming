import sys
import heapq
from heapq import heappush, heappop

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(int(line.rstrip()))


	for i in range(1, len(q)):
		res = [0] * q[i]
		r = q[i]
		l = 1
		d = r - l + 1
		to_put = 1
		h = []
		heappush(h, (1, (l, r)) ) # doesnt matter what val is b/c its going to be popped
		while(len(h) != 0):
			# print(h)
			curr = heappop(h)
			pair = curr[1] 
			l = pair[0]
			r = pair[1]
			# print(pair)
			if (r - l + 1) % 2 == 0:
				middle = (l+r - 1) // 2
				res[ middle - 1 ] = str(to_put)
			else:
				middle = (l+r) // 2
				res [ middle - 1 ] = str(to_put)
			to_put +=1
			# append the splits
			heappush(h, (-1*(middle - l), (l, middle-1))) # push left
			heappush(h, (-1 * (r - middle), (middle+1, r))) # push right 
			if to_put == q[i]+1:
				break
		print(" ".join(res))
		

if __name__ == '__main__':
	main()