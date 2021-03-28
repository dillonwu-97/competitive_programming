class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        ret = []
        m = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', 
                   '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
                if len(digits) == 0:
            return []
        def solve(prev, digits):
            if len(digits) == 1:
                for i in m[digits[0]]:
                    ret.append(prev + i)
            else:
                for i in m[digits[0]]:
                    solve(prev + i, digits[1:])
        solve("", digits)
        return ret