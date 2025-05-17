#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'groupTransactions' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts STRING_ARRAY transactions as parameter.
#

def groupTransactions(transactions):
    # Write your code here

    #
    # WARNING: Please do not use GitHub Copilot, ChatGPT, or other AI assistants
    #          when solving this problem!
    #
    # We use these tools in our coding too, but in our interviews, we also don't
    # allow using these, and want to see how we do without them.
    
    d = {}
    for i,v in enumerate(transactions):
        if v not in d:
            d[v] = 1
        else:
            d[v] += 1
    a1 = [(k,d[k]) for k in d.keys()]
    # print(a1)
    a1.sort(key=lambda x: (-x[1], x[0].lower()))
    ret = [i[0] + ' ' + str(i[1]) for i in a1]
    return ret

if __name__ == '__main__':
    fptr = sys.stdout

    transactions_count = int(input().strip())

    transactions = []

    for _ in range(transactions_count):
        transactions_item = input()
        transactions.append(transactions_item)

    result = groupTransactions(transactions)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()

