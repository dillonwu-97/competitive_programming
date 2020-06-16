# Matrix Game
import sys

def solve(m):
	# for i in m:
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		# q[i] = [int(x) for x in q[i]]

	i = 1
	while (i < len(q)):
		# print(q[i])
		rows = int(q[i][0])
		cols = int(q[i][1])
		m = []
		m_cols = []
		for j in range(1,rows + 1):
			m.append(q[i + j])
		# print(m)
		for k in range(cols):
			temp = [m[j][k] for j in range(len(m))]
			m_cols.append(temp)
		
		count = 0
		count2 = 0
		for k in m:
			if "1" in k:
				continue
			else:
				count +=1
		for k in m_cols:
			if "1" in k:
				continue
			else:
				count2+=1
		count = min(count2, count)

		if count % 2 == 0:
			print("Vivek")
		else:
			print("Ashish")

		# solve(q[i])
		# print(rows)
		i+=rows + 1

if __name__ == '__main__':
	main()