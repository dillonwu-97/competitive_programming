# Polygon
import sys

def solve():
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		# q[i] = [int(x) for x in q[i]]

	start = 1
	while (start < len(q)):
		size = q[start][0]
		ret = "YES"
		test = []
		for j in range(1, int(size)+1):
			temp = list(q[start+j][0])
			# print(temp)
			test.append(temp)

		for i in range(len(test)):
			for j in range(len(test[0])):
				if test[i][j] == '1':
					if j+1 < len(test[0]) and i+1 < len(test):
						if test[i][j+1] == '0' and test[i+1][j] == '0':
							ret = "NO"
					# if j+1 == len(test[0]) and i+1 < len(test):
					# 	if test[i+1][j] == '0':
					# 		ret = "NO"
					# if i+1 == len(test) and j+1 < len(test[0]):
					# 	if test[i][j+1] == '0':
					# 		ret + "NO"

		start += int(size)+1
		print(ret)
		

if __name__ == '__main__':
	main()