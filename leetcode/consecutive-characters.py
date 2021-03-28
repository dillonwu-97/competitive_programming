class Solution(object):
    def maxPower(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        count = 1
        m = 0
        char = ''
        for i in s:
            if i == char:
                count+=1
            else:
                if count > m:
                    m = count
                char = i
                count = 1
        if count > m:
            m = count
        return m