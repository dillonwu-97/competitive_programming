import sys

def swap(x, y, a):
	temp = a[x]
	a[x] = a[y]
	a[y] = temp
	return a

def solve():
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q),2):
		flags = q[i][0]
		road = q[i][1]
		a = q[i+1]
		# print(flags, road, a)
		da = 0 # distance a
		db = road
		time = 0
		ma = 1 # mps for a
		mb = 1
		ta = 0 # time to next flag
		tb = 0 
		i = 0 # index for flags
		j = len(a) -1 # index for flags in reverse
		prev_i = 0
		prev_j = road
		temp = 0
		# check has intersected yet or has not intersected yet
		while (i <= j):
			da = a[i] - prev_i
			db = prev_j - a[j]
			ta = da / ma # ma = m/s; ta = time traveled
			tb = db / mb
			# if time to next flagpost is the same
			if ta == tb:
				time += (1 / ma * da)
				# increment mps
				ma+=1
				mb+=1
				# prev location / # distance travelled until next flapost
				prev_i = a[i]
				prev_j = a[j]
				# increment pointers
				i+=1
				j-=1
				if (prev_i > prev_j):
					prev_i -= da
					prev_j += db
					break
			# if A got there faster than B
			elif ta < tb:
				temp = (1 / ma * da)
				time += temp
				ma += 1
				prev_i = a[i]
				prev_j -= (temp * mb) # distance traveled by a timesspeed of b 
				i+=1
				if (prev_i > prev_j):
					prev_i -= da
					prev_j -= (temp * mb)
					break
			else:	# do a only, not b
				temp = (1 / mb * db)
				time += temp
				mb+=1
				prev_j = a[j]
				prev_i += (temp * ma)
				j-=1
				if (prev_i > prev_j):
					prev_i -= (temp * ma)
					prev_j -= db
					break
		# this means that we crossed so maintain speed until we reach each other
		# print(i, j, time, prev_i, prev_j, ma, mb)
		# if i >= j:
			# add distance left divided by time both cards take to see each other
		time += ( (prev_j - prev_i) / (ma + mb) )
		# this means that the distance exceeded each other

		print(time)
		# solve(q[i])

if __name__ == '__main__':
	main()