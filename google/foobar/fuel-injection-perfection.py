'''
Fuel Injection Perfection
=========================

Commander Lambda has asked for your help to refine the automatic quantum antimatter fuel injection system for the LAMBCHOP doomsday device. It's a great chance for you to get a closer look at the LAMBCHOP -- and maybe sneak in a bit of sabotage while you're at it -- so you took the job gladly. 

Quantum antimatter fuel comes in small pellets, which is convenient since the many moving parts of the LAMBCHOP each need to be fed fuel one pellet at a time. However, minions dump pellets in bulk into the fuel intake. You need to figure out the most efficient way to sort and shift the pellets down to a single pellet at a time. 

The fuel control mechanisms have three operations: 

1) Add one fuel pellet
2) Remove one fuel pellet
3) Divide the entire group of fuel pellets by 2 (due to the destructive energy released when a quantum antimatter pellet is cut in half, the safety controls will only allow this to happen if there is an even number of pellets)

Write a function called solution(n) which takes a positive integer as a string and returns the minimum number of operations needed to transform the number of pellets to 1. The fuel intake control panel can only display a number up to 309 digits long, so there won't ever be more pellets than you can express in that many digits.

For example:
solution(4) returns 2: 4 -> 2 -> 1
solution(15) returns 5: 15 -> 16 -> 8 -> 4 -> 2 -> 1
Quantum antimatter fuel comes in small pellets, which is convenient since the many moving parts of the LAMBCHOP each need to be fed fuel one pellet at a time. However, minions dump pellets in bulk into the fuel intake. You need to figure out the most efficient way to sort and shift the pellets down to a single pellet at a time. 

The fuel control mechanisms have three operations: 

1) Add one fuel pellet
2) Remove one fuel pellet
3) Divide the entire group of fuel pellets by 2 (due to the destructive energy released when a quantum antimatter pellet is cut in half, the safety controls will only allow this to happen if there is an even number of pellets)

Write a function called solution(n) which takes a positive integer as a string and returns the minimum number of operations needed to transform the number of pellets to 1. The fuel intake control panel can only display a number up to 309 digits long, so there won't ever be more pellets than you can express in that many digits.

For example:
solution(4) returns 2: 4 -> 2 -> 1
solution(15) returns 5: 15 -> 16 -> 8 -> 4 -> 2 -> 1

Languages
=========

To provide a Python solution, edit solution.py
To provide a Java solution, edit Solution.java

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Python cases --
Input:
solution.solution('15')
Output:
    5

Input:
solution.solution('4')
Output:
    2

-- Java cases --
Input:
Solution.solution('4')
Output:
    2

Input:
Solution.solution('15')
Output:
    5

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.
'''
def solution(n):
	a = bin(int(n))[2:][::-1]
	count = 0
	i = 0
	
	while (i < len(a)):
		temp = 0
		if a[i] == '1':
			temp = 0
			while (i < len(a) and a[i] == '1' ):
				if i == len(a) - 1:
					if temp > 0:
						if temp == 1:
							return count + temp + 1;
						else:
							return count + temp + 2;
					else:
						return count;	
				temp += 1
				i+=1
			if temp != 1:
				a = a[:i] + '1' + a[i+1:] # convert from '0' -> '1' if not the last
			count += temp + 1
		else:
			while (i < len(a) and a[i] == '0'  ):
				count += 1
				i += 1

	return count 

print(solution('2080193948352450442442011401061206244388810931376389970099979679208467138393837292617102774682089829698971384777136032462368602450518509756581029441021'))
print(solution('2152901187517739656201386993805303814751691651839392383217318456189714856585586004885382618326196940882737531523024153867405350577531291091825893542833'))
print(solution('3'))
print(solution('17'))
print(solution('22'))
	
