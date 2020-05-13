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

	for i in range(2, len(q), 2):
		print(q[i])
		eat = q[i]
		a = 0 #alice ate
		b = 0 #bob ate
		t = 0 #total turns
		must = eat[0] - 1 # have to eat this much for next turn
		i = 0 #pointers
		j = len(eat) - 1
		while (i < j and j > i and t < 10):
			# alice turn
			print(must)
			current = 0
			if t%2 == 0:
				while (i < j and current < must):
					a+= eat[i]
					current += eat[i]
					i+=1
					print("i is: " + str(i))
					print("a is: " + str(a))
			else:
				while (j> i and current < must):
					b+= eat[j]
					current += eat[j]
					j-=1
					print("j is: " + str(j))
					print("b is: " + str(b))
			must = current
			t+=1
			print("t is: " + str(t))
			#bob turn
		print('k')
		print(t, a, b)
		break
		# solve(q[i])


if __name__ == '__main__':
	main()