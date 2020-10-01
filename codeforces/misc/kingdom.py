# Linova and Kingdom

import sys
from collections import Counter
from heapq import nlargest 

def solve(arr, t):
	links = {}
	shortest = {}
	count = Counter()
	visited = []
	start = [1]
	all_nodes = []
	while len(start) > 0:
		search = start.pop(0)
		count[search] = 0
		for edge in arr:
			if edge in visited:
				continue
			to_append = -1
			if edge[0] == search:
				to_append = edge[1]
			elif edge[1] == search:
				to_append= edge[0]
			if to_append != -1:
				# links to 1
				start.append(to_append)
				if to_append in links:
					links[to_append].append(search)
				else:
					links[to_append] = [search]
				visited.append(edge)

				# most nodes
				count[search] += 1
				# if search in shortest:
				# 	shortest[search].append(to_append)
				# else:
				# 	shortest[search] = [to_append]
			all_nodes.append(edge[0])
			all_nodes.append(edge[1])
	
	res = nlargest(t, count, key = count.get) 
	all_nodes = list(set(all_nodes))
	# print(res)
	# print(count)
	# print(links)
	total = 0
	for i in all_nodes:
		if i not in res:
			q = [links[i]]
			# print(i)
			while len(q) != 0:
				qop = q.pop()[0]
				if qop in res:
					total+=1
				if qop != 1:
					q.append(links[qop])


	return total

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	# print(q[1:])
	tourist = q[0][0] - q[0][1]
	print(solve(q[1:], tourist))

	# for i in range(0, len(q)):
		# print(q[i])
		# solve(q[i])

if __name__ == '__main__':
	main()