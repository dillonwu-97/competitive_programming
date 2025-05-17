#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'processLogs' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. STRING_ARRAY logs
#  2. INTEGER maxSpan
#

def processLogs(logs, maxSpan):
    # Write your code here

    #
    # WARNING: Please do not use GitHub Copilot, ChatGPT, or other AI assistants
    #          when solving this problem!
    #
    # We use these tools in our coding too, but in our interviews, we also don't
    # allow using these, and want to see how we do without them.
    # print(logs)
    # print(maxSpan)
    d = {}
    ret = []
    for i,v in enumerate(logs):
        temp = v.split(" ")
        id = int(temp[0])
        ti = int(temp[1])
        # print(id, ti)
        op = temp[2]
        if id not in d:
            d[id] = ti 
        else:
            diff = abs(ti - d[id])
            # if id == 155479500:
            #     print(diff, maxSpan)
            #     input()
            if diff <= maxSpan:
                ret.append((id, diff))
    ret.sort(key = lambda x: x[0])
    return [str(i[0]) for i in ret]

    

if __name__ == '__main__':
    fptr = sys.stdout

    logs_count = int(input().strip())

    logs = []

    for _ in range(logs_count):
        logs_item = input()
        logs.append(logs_item)

    maxSpan = int(input().strip())

    result = processLogs(logs, maxSpan)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
