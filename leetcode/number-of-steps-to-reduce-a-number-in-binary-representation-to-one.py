class Solution:
    def numSteps(self, s: str) -> int:
        a = s[::-1]
        count = 0
        i = 0
        while (i < len(a)):
                temp = 0
                if a[i] == '1':
                        temp = 0
                        while (i < len(a) and a[i] == '1' ):
                                if i == len(a) - 1:
                                        if temp > 0:
                                                return count + temp + 2;
                                        else:
                                                return count;
                                temp += 1
                                i+=1
                        a = a[:i] + '1' + a[i+1:] # convert from '0' -> '1' if not the last
                        count += temp + 1
                else:
                        while (i < len(a) and a[i] == '0'  ):
                                count += 1
                                i += 1
        return count