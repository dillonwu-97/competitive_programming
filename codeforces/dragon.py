# Kana and Dragon Quest

import sys
import math

def v (num):
	return math.floor(num // 2) + 10

def l (num):
	return num - 10

def solve(arr):
	hp = arr[0]
	vcount = arr[1]
	lcount = arr[2]
	l = arr[2] * 10
	if l > arr[0]: 
		return "YES"
	while hp > 20 and vcount != 0:
		hp = v(hp)
		vcount -=1
	if l >= hp:
		return "YES"
	else:
		return "NO"

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q)):
		# print(q[i])
		print(solve(q[i]))

if __name__ == '__main__':
	main()