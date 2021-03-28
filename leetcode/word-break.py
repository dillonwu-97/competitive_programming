import sys
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        # this is def backtracking
                lengthwords = {}
        minword = sys.maxsize
        for i in wordDict:
            # keep track of min length
            if len(i) < minword:
                minword = len(i)
            lengthwords[i] = 0
        table = [-1] * (len(s) + 1)
        # print(usedwords, lengthwords)
        # also need to keep track of whether or not all words were used or not
        def solve(start, word, wordDict):
            if len(word[start:]) == 0:
                return True
            elif len(word[start:]) < minword:
                table[start] = 0
                return False
            else:
                ret = True
                for i in range(start + 1, len(word)+1):
                    if table[i] == 0:
                        continue
                    else:
                        if word[start:i] in lengthwords:
                            ret = True and solve(i, word, wordDict)
                            if ret == False:
                                continue
                            else: 
                                return True
                table[start] = 0
                # print(table)
                return False
        ans = solve(0,s, wordDict)
        return ans
                                                                                                                                                                                