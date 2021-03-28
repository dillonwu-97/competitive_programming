class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        a = s.split(" ")
        a = [i for i in a if len(i) > 0]
        a.reverse()
        return " ".join(a)