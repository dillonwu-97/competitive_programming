
import sys
import math

def bc(n, k): 
    # since C(n, k) = C(n, n - k) 
    if(k > n - k): 
        k = n - k 
    # initialize result 
    res = 1
    # Calculate value of  
    # [n * (n-1) *---* (n-k + 1)] / [k * (k-1) *----* 1] 
    for i in range(k): 
        res = res * (n - i) 
        res = res / (i + 1) 
    return res 


def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	n = q[0][0]
	d = q[0][1]
	a = q[1]
	# print(n, d, a)
	i = 0
	j = 1
	n_vals = []
	count = 1
	ret = 0
	while (i < len(a)):
		while (j < len(a) and a[i] + d >= a[j]):
			if count >= 2:
				ret += bc(count, 2)
			count += 1
			j+=1
		i+=1
		count = max(count - 1, 1)
		if i == j:
			j+=1

	print(int(ret))

	# n choose next value not previous value 
	# need to find out how to exclude previous values
	# i think the overlapping values would be number of overlapping values choose k
	# so new value would be overlapping + new values choose k
	# and diff is overlapping + new values choose k - overlapping values choose k

		

if __name__ == '__main__':
	main()