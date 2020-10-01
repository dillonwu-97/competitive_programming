#604, D2, #1
import sys

def beautiful_string(string):
	start = string[0]
	answer = -1

	#first check
	for i in range(1, len(string)):
		if string[i] != '?' and string[i-1] != '?' and string[i] == string[i-1]:
			return answer

	#insertion
	if (len(string) == 1 and string == '?'):
		string = 'a'


	possible = ['a','b','c']
	temp = string
	string = list(string)
	if (len(string) > 2):
		for i in range (1, len(string)-1):
			if string[i] == '?':
				for j in possible:
					string[i] = j
					if string[i] != string[i+1] and string[i] != string[i-1]: break	


	#edge case (first and last characters)
	if (string[0] == '?'): 
		for j in possible:
			string[0] = j
			if string[0] != string[1]: break	

	i = len(string) - 1
	if (string[len(string) -1 ] == '?'):
		for j in possible:
			string[i] = j
			if string[i] != string[i-1]: break	
	
	string = "".join(string)
	return string

def main():
	store = []
	for line in sys.stdin.readlines():
		store.append(line)

	for i in range(len(store)):
		store[i] = store[i].rstrip()
		
	for string in range(1,len(store)): 
		print(beautiful_string(store[string]))



if __name__ == "__main__":
	main()