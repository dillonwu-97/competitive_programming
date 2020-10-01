import sys
import string

alph = list(string.ascii_lowercase) 
def solve(arr):
	strlen = arr[0]
	sublen = arr[1]
	count = arr[2]
	ret = ''

	ctrack = 0
	for i in range(strlen):
		ret += alph[ctrack]
		ctrack+=1
		if (ctrack == count):
			ctrack = 0
		if ctrack == sublen:
			ctrack = 0
	return ret


def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	# print(alph)
	for i in range(1, len(q)):
		# print(q[i])
		ret = solve(q[i])
		print(ret)

if __name__ == '__main__':
	main()