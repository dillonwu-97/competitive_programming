#beautiful_num.py
import sys

def beautiful_num(size, num):
	num = list(num)
	result = [0] * size
	substring = []
	flag = 0
	for i in range(size):
		print('i is: ' + str(i))
		offset = num[i] - 1
		if (i - offset > 0):
			substring = num[i - offset: i+1]
			substring.sort()
			result[num[i]] = neighbor(substring)
		if (i + offset < len(num)):
			substring = num[i: i + offset+1]
			substring.sort()
			#print(substring)
			result[num[i]] = neighbor(substring)
	return result

def neighbor(substring):
	print(substring)
	for i in range(1, len(substring)):
		if substring[i] != substring[i-1] + 1:
			return 0
	return 1


def main():
	'''
	store = []
	for line in sys.stdin.readlines():
		store.append(line)

	for i in range(len(store)):
		store[i] = store[i].rstrip()
	
	'''
	'''
	#works
	test = [1,2,3,4,5]
	print(neighbor(test))
	print(neighbor(test + [7]))
	'''

	test = [4,5,1,3,2,6]
	print(beautiful_num (len(test), test))



if __name__ == "__main__":
	main()