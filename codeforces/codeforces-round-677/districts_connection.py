import sys
from collections import defaultdict
from collections import deque

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
		d = defaultdict(list)
		m = 0
		for i in range(len(a)):
			d[ a[i] ].append(i+1)
			if len(d[ a[i] ]) > m:
				m = len(d[ a[i] ])
		# print(d)
		# actually problem was easier than i thought
		if len(d) == 1:
			print("NO")
		else:
			print("YES")
			cur = a[0]
			# print("cur is ", cur, a[0])
			for k in d.keys():
				if k != cur:
					for i in d[k]:
						print(d[cur][0], i)
			if len(d[a[0]]) > 1:
				for j in range(1,len(d[a[0]])):
					print(i, d[a[0]][j])


		# print ("comparison ", m, len(a) // 2 + 1)
		# diff = len(a) // 2
		# if len(a) % 2 == 1: diff +=1
		# if m > diff:
		# 	print ("NO")
		# 	continue
		# else:
		# 	print("YES")
		# 	sorted_list = deque()
		# 	count = 0
		# 	for k in sorted(d, key=lambda x: len(d[x])):
		# 		# print(d[k])
		# 		if count % 2 == 0:
		# 			sorted_list.extend(d[k])
		# 		else:
		# 			sorted_list.extendleft(d[k])
		# 		count+=1
		# 	# print(sorted_list)
		# 	i = 0
		# 	j = len(sorted_list) - 1
		# 	ret_list = []
		# 	while i < j:
		# 		ret_list.append(sorted_list[i])
		# 		ret_list.append(sorted_list[j])
		# 		i+=1
		# 		j-=1
		# 	if i == j: ret_list.append(sorted_list[i])
		# 	for i in range(len(ret_list)-1):
		# 		print(ret_list[i], ret_list[i+1])

			# print(sorted_list)
		# solve(q[i])

if __name__ == '__main__':
	main()