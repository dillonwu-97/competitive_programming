import sys

def solve(inp, counter):
	inp = list(set(inp))
	inp.sort()
	save = 0
	track = 0 # keeps track of input list
	while counter!= 0 or track < len(inp):
		if track >= len(inp):
			save += counter
			break
		if (inp[track] == save+1):
			save+=1
			track+=1
		elif track < len(inp) and counter == 0:
			if inp[track] == inp[track-1]+1:
				save+=1
				track+=1
				continue
			else:
				break
		else:
			counter-=1
			save+=1
	return save


def main():
	queries = []
	for line in sys.stdin.readlines():
		queries.append(line)

	for i in range(len(queries)):
		queries[i] = queries[i].rstrip()

	for i in range(1,len(queries), 2):
		temp = queries[i+1].split(' ')
		inp = [int(x) for x in temp]
		temp = queries[i].split(' ')
		counter = int(temp[1])
		sol = solve(inp, counter)
		print(sol)

if __name__ == '__main__':
	main()