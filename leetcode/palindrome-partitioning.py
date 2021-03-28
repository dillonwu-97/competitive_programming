class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
                # check palindrome
        def cp(s):
            if s == s[::-1]:
                return True
            else:
                return False
        ret = [] 
        # a = [] # the temporary palindrome list that gets updated
        # s = string, p = partition
        # if length is less than l: return, else append
        def solve(s, a, ret):
            if len(s) == 0:
                ret.append(a)
                return a
            else:
                for i in range(1,len(s)+1):
                    # print('one', i, s[:i], a)
                    if cp(s[:i]):
                                                a.append(s[:i])
                        # print(a)
                        a = solve(s[i:],a,ret)
                        # print('two', i, len(s), s[:i], a)
                        a = a[:-1]
                        # print('three', i, len(s), s[:i], a)
                    # print(a)
                    # a = a[:-1]
                # print(a)
                return a
                        # for i in range(len(s)-1):
        #     ret.append(solve(s[i:], []) + solve(s[:i], []))
        solve(s, [], ret)
        return ret