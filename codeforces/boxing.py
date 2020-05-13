
#1. Find the index of friend first
#2. find how many are weaker than friend; these will always be a pair until u run out
def weakMatch(array, size):
	

#The solution is this: separator is friend -> even or odd
#for strong match, match the highest cost with someone stronger; 
#if the strongest has the highest cost, then match with second highest cost
#for weak match whomever is fine
#match friend with friend -1 and if 
#friend is even match leftover from left and right side with each other 
#find index of stronger - 1


def match (array, size):
	#do the matching 
	while (size != 1):
		friend = array.index(-1)
		if friend %2 == 0: 
			leftover = 1 #There will be leftover from weak and strong match 
		visited = []
		array, visited = strongmatch(array, visited, friend)
		array, visited = friendmatch(array, visited)
		weakmatch()
		if leftover ==1: leftover()

def strongmatch(array, visited, friend):
	#friend is the starting cutoff
	#array is dynamically changing
	for i in range(friend + 1, len(array)):
		temp = array[friend + 1:len(array)] #store stuff i have to deal with at each iteration
		hi = max(temp) #find most expensive
		temp.remove(hi) #drop from temp
		hi_index = array.index(hi) #index of hi
		if hi_index == len(array)-1:
			#find second highest element in array 
			hi2 = max(temp)
			hi2_index = array.index(hi2)
			del array[hi2_index]
		else:
			#find weakest one that is cheaper than current highest cost
			for j in range(hi_index + 1, len(array)):
				if (array[j] )








def main():
	test = [11, -1, 13, 19, 24, 7, 17, 5]
	size = len(test)

	weakMatch(test, size)


if __name__ == "__main__":
	main()