class Solution(object):
    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        vowels = ['a','e','i','o','u']
        m = 0 # max size
        msub = s[:k] # max string
        for i in msub:
            if i in vowels:
                m+=1
        currentsub = msub
        current = m
                for i in range(k, len(s)):
            # adding new letter
            if s[i] in vowels:
                if currentsub[0] not in vowels:
                    current+=1
            else:
                # if new letter is not a vowel, and the exiting letter is a 
                    vowel, subtract
                if currentsub[0] in vowels:
                    current-=1
            currentsub = currentsub[1:] + s[i]
            if current > m:
                m = current
                msub = currentsub
                            return m
        