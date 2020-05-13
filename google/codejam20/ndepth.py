import sys

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip()

	case = 1
	for i in range(1, len(q)):
		ret = ''
		left = 0
		val = 0
		for j in q[i]:
			val = int(j)
			if val== left:
				ret+=j
				continue 
			elif val > left:
				ret += '(' * (val - left) + j
			elif val < left:
				ret += ')' * (left - val) + j
			left = val
		ret+= ')' * val
		print('Case #' + str(case) + ': ' + str(ret))
		case +=1

if __name__ == '__main__':
	main()