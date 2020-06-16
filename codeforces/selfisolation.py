# B. Maria Breaks the Self-isolation
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
		total = 1
		h = {}
		for i in a:
			if i not in h:
				h[i] = 1
			else:
				h[i] += 1

		key_l = []
		for key in h.keys():
			key_l.append(key)
		key_l.sort(reverse = True)
		total += sum(h.values())
		# print(key_l)
		for i in key_l:
			if total > i:
				break
			else:
				total -= h[i]
		# print(h)
		print(total )


if __name__ == '__main__':
	main()