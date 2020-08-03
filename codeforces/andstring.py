import sys

def swap(x, y, a):
	temp = a[x]
	a[x] = a[y]
	a[y] = temp
	return a

def help(temp):
	if (temp[0] == 'a' or temp[0] == '?') and\
	(temp[1] == 'b' or temp[1] == '?') and\
	(temp[2] == 'a' or temp[2] == '?') and\
	(temp[3] == 'c' or temp[3] == '?') and\
	(temp[4] == 'a' or temp[4] == '?') and\
	(temp[5] == 'b' or temp[5] == '?') and\
	(temp[6] == 'a' or temp[6] == '?'): 
		return True
	else:
		return False


def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')[0]
		# q[i] = [int(x) for x in q[i]]

	for j in range(1, len(q), 2):
		# print(q[i+1])
		# Two pass algorithm might be better
		# s = list(q[i+1])
		s = q[j+1]
		tf = 'abacaba'
		ans = 'No'
		# print(s)
		for i in range(0, len(s)-6):
			temp = s[i:i+7]
			if temp == tf and ans == 'YES':
				ans = 'NO'
				break
			if temp == tf and ans == 'No':
				ans = 'YES'

		# means that there was a double 
		if ans == 'NO':
			print(ans)
			continue

		# no double, replace all '?' with 'z'
		if ans == 'YES':
			s = s.replace('?', 'z')
			print(ans)
			print(s)
			continue
		ans = "No"
		# could not find 
		i = 0
		while(i < len(s)-6):
			# need to handle edge case like 'abacab?bacaba'
			# another edge case would be something like 'abacab?caba'	
			if help(s[i:i+7]) == True:
				temp = s # save s in case we fuck up
				s = s[:i] + 'abacaba' + s[i+7:]
				if (i+13) <= len(s) and s[i:i+7] == s[i+6:i+13][::-1]:
				# print('hello ', s[i:i+7], s[i+6:i+13][::-1])
					i+= 1
					s = temp
					continue
				if (i+11) <= len(s) and s[i:i+6] == s[i+5:i+11][::-1]:
					# print('hello ', s[i:i+6], s[i+5:i+11][::-1])
					i+=1
					s = temp
					continue
				# need to check behind as well
				# print('hello ', s[i-6:i+1], s[i:i+7], 'ok')
				if i >= 6 and s[i-6:i+1] == s[i:i+7]:
					i+= 1
					s = temp
					continue
				
				if i >= 4 and s[i-4:i+2] == s[i+1:i+7][::-1]:
					# print('hello ', s[i-4:i+2], s[i+1:i+7][::-1])
					i+= 1
					s = temp
					continue
				
				ans = 'Yes'
				break
			else:
				i+=1
		if ans == 'Yes':
			s = s.replace('?', 'z')
			print(ans)
			print(s)
		else: 
			print(ans)



if __name__ == '__main__':
	main()