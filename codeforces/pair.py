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
		used = {}
		dontuse = {}
		even = []
		odd = []
		ret = "NO"
		for i in a:
			if i%2 == 0:
				even.append(i)
			else:
				odd.append(i)
			used[i] = 0
		if len(even)%2 == 0 and len(odd)%2 == 0:
			ret = "YES"
		# find the n-1 parity case
		elif len(even)%2 == 1 and len(odd)%2 == 1:
			for i in even:
				if i-1 in used:
					ret = "YES"
			if ret == "NO":
				for i in odd:
					if i-1 in used:
						ret = "YES"
		print(ret)
		# for i in a:
		# 	if i not in used:
		# 		used[i] = 1
		# 	else:
		# 		used[i] +=1
		# # find parities for n - 1
		# track = 0
		# # print(a)
		# while(track != len(a)):
		# 	i = a[track]
		# 	if i-1 in used and used[i-1] > 0:
		# 		used[i-1] -=1
		# 		dontuse[i-1] = 0
		# 		a.pop(track)
		# 		track-=1
		# 	track+=1
		# # find even odd parities
		# print(a)
		# print(dontuse)
		# for i in a:
		# 	if i % 2 == 0 and i not in dontuse:
		# 		even.append(i)
		# 	elif i%2 == 1 and i not in dontuse:
		# 		odd.append(i)
		# if len(even)%2 == 0 and len(odd)%2 == 0:
		# 	print("YES")
		# else:
		# 	print("NO")
		





		# solve(q[i])

if __name__ == '__main__':
	main()