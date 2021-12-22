'''
Doomsday Fuel
=============

Making fuel for the LAMBCHOP's reactor core is a tricky process because of the exotic matter involved. It starts as raw ore, then during processing, begins randomly changing between forms, eventually reaching a stable form. There may be multiple stable forms that a sample could ultimately reach, not all of which are useful as fuel. 

Commander Lambda has tasked you to help the scientists increase fuel creation efficiency by predicting the end state of a given ore sample. You have carefully studied the different structures that the ore can take and which transitions it undergoes. It appears that, while random, the probability of each structure transforming is fixed. That is, each time the ore is in 1 state, it has the same probabilities of entering the next state (which might be the same state).  You have recorded the observed transitions in a matrix. The others in the lab have hypothesized more exotic forms that the ore can become, but you haven't seen all of them.

Write a function solution(m) that takes an array of array of nonnegative ints representing how many times that state has gone to the next state and return an array of ints for each terminal state giving the exact probabilities of each terminal state, represented as the numerator for each state, then the denominator for all of them at the end and in simplest form. The matrix is at most 10 by 10. It is guaranteed that no matter which state the ore is in, there is a path from that state to a terminal state. That is, the processing will always eventually end in a stable state. The ore starts in state 0. The denominator will fit within a signed 32-bit integer during the calculation, as long as the fraction is simplified regularly. 

For example, consider the matrix m:
[
  [0,1,0,0,0,1],  # s0, the initial state, goes to s1 and s5 with equal probability
  [4,0,0,3,2,0],  # s1 can become s0, s3, or s4, but with different probabilities
  [0,0,0,0,0,0],  # s2 is terminal, and unreachable (never observed in practice)
  [0,0,0,0,0,0],  # s3 is terminal
  [0,0,0,0,0,0],  # s4 is terminal
  [0,0,0,0,0,0],  # s5 is terminal
]
So, we can consider different paths to terminal states, such as:
s0 -> s1 -> s3
s0 -> s1 -> s0 -> s1 -> s0 -> s1 -> s4
s0 -> s1 -> s0 -> s5
Tracing the probabilities of each, we find that
s2 has probability 0
s3 has probability 3/14
s4 has probability 1/7
s5 has probability 9/14
So, putting that together, and making a common denominator, gives an answer in the form of
[s2.numerator, s3.numerator, s4.numerator, s5.numerator, denominator] which is
[0, 3, 2, 9, 14].

Languages
=========

To provide a Java solution, edit Solution.java
To provide a Python solution, edit solution.py

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Java cases --
Input:
Solution.solution({{0, 2, 1, 0, 0}, {0, 0, 0, 3, 4}, {0, 0, 0, 0, 0}, {0, 0, 0, 0,0}, {0, 0, 0, 0, 0}})
Output:
	[7, 6, 8, 21]

Input:
Solution.solution({{0, 1, 0, 0, 0, 1}, {4, 0, 0, 3, 2, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}})
Output:
	[0, 3, 2, 9, 14]

-- Python cases --
Input:
solution.solution([[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0,0], [0, 0, 0, 0, 0]])
Output:
	[7, 6, 8, 21]

Input:
solution.solution([[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]])
Output:
	[0, 3, 2, 9, 14]

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.
'''
# infinite geometric series problem
import math
#from math import gcd # python 3
import numpy as np
from fractions import Fraction
from fractions import gcd # python2.7

def subtract(a, b):
	# subtract matrix b from a
	n = xrange(len(a))
	return [[a[i][j] - b[i][j] for j in n] for i in n]


def identity(m):
	# identity matrix for matrix m
	n = xrange(len(m))
	return [[1 if i == j else 0 for j in n] for i in n]


def multiply(a, b):
	# multiply matrices a x b
	return [[sum(i * j for i, j in zip(r, c)) for c in zip(*b)] for r in a]


def invert(a):
	b = identity(a)
	for d in xrange(len(a)):
		to1 = Fraction(1, a[d][d])
		for j in xrange(len(a)):
			a[d][j] *= to1
			b[d][j] *= to1
		for i in range(len(a))[0:d] + range(len(a))[d + 1 :]:
			to0 = a[i][d]
			for j in xrange(len(a)):
				a[i][j] = a[i][j] - to0 * a[d][j]
				b[i][j] = b[i][j] - to0 * b[d][j]
	return b

def lcm(a):
	lcd = 1
	for i in a:
		lcd = (i * lcd) // gcd(i, lcd)
		# lcm = (i / gcd(i,lcd)) * lcd
	return lcd
# Geometric series algorithm for a matrix
def mat_geo(m):
	ret = np.identity(len(m))
	ret = ret.tolist()
	for i in range(len(ret)):
		for j in range(len(ret[0])):
			ret[i][j] = Fraction(ret[i][j]) - m[i][j]
	ret = invert(ret)
	return ret

def solution(m):
	# Find all terminals and nonterminals

	terminals = []
	nonterm = []
	for i in range(len(m)):
		if len(set(m[i])) == 1 and m[i][0] == 0:
			terminals.append(i)
		else:
			nonterm.append(i)
	if len(terminals) == 0:
		return []
	if len(terminals) == len(m): 
		ret = [0] * len(m)
		ret[0] = 1
		ret.append(1)
		return ret
	if len(set(m[0])) == 1 and m[0][0] == 0:
		ret = [0] * len(terminals)
		ret[0] = 1
		ret.append(1)
		return ret
	terminals = sorted(terminals)

	nt = np.zeros((len(nonterm), len(nonterm)))
	t = np.zeros((len(nonterm), len(terminals)))

	nt = nt.tolist()
	t = t.tolist()


	# Calculate geometric series using formula
	sums = [sum(m[i]) for i in range(len(m))]
	for i in range(len(m)):
		for j in range(len(m[0])):
			if m[i][j] != 0:
				m[i][j] = Fraction(m[i][j], sums[i])	

	for i in range(len(nonterm)):
		for j in range(len(nonterm)):
			nt[i][j] = m[nonterm[i]][nonterm[j]]

	for i in range(len(nonterm)):
		for j in range(len(terminals)):
			t[i][j] = m[nonterm[i]][terminals[j]]


	nt = mat_geo(nt)

	A = nt
	B = t
	M = multiply(A,B)
	M = M[0]
	denom = []
	for i in range(len(M)):
		denom.append(M[i].denominator)
	common = lcm(denom)
	ret = []
	for i in range(len(M)):
		ret.append(int(M[i].numerator * common / M[i].denominator))
	ret.append(int(common))
	return ret

# 	return [int(x.numerator * common / x.denominator) for x in M] + [int(common)]

# https://cs.stackexchange.com/questions/67487/what-algorithm-to-find-end-state-probabilities
# https://github.com/ivanseed/google-foobar-help/blob/master/challenges/doomsday_fuel/doomsday_fuel.md
def main():
	m = [[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
	# m = [[0,0,0],[0,0,0],[0,0,0]]
	m = [[0,1],[0,0]]
	m = [[1, 1, 1, 1, 1,],  [0, 0, 0, 0, 0,], [1, 1, 1, 1, 1,], [0, 0, 0, 0, 0,], [1, 1, 1, 1, 1,]]
	m = [[0]]
	# m = [[0,0],[0,0]] # -> [1,0,1]
	m = [[0,1],[0,0]] # -> 1,1
	m = [[1,0],[0,0]] # -> [0,1]
	# m = [[1,1],[1,1]]
	m = [[5, 9, 9, 5, 3, 2, 8, 1, 6, 5], [2, 3, 1, 2, 6, 6, 6, 6, 4, 2], [5, 9, 8, 1, 7, 5, 5, 7, 6, 2], [8, 7, 6, 6, 9, 7, 1, 8, 9, 2], [6, 5, 8, 1, 7, 3, 3, 1, 5, 5], [1, 8, 9, 7, 8, 5, 5, 4, 3, 5], [4, 3, 1, 3, 4, 8, 3, 7, 5, 8], [2, 2, 5, 6, 1, 7, 5, 6, 7, 5], [4, 9, 9, 3, 8, 2, 5, 5, 9, 6], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

	print(solution(m))

	

if __name__ == '__main__':
	main()	
