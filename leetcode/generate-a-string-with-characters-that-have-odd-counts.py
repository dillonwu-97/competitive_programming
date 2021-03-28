class Solution(object):
    def generateTheString(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = ''
        if n == 0:
            s = ''
        elif n == 1:
            s = 'a'
        elif n%2==0:
            s = 'a'*(n-1) + 'b'
        else:
            s = 'a'*(n-2) + 'b' + 'c'
        return s