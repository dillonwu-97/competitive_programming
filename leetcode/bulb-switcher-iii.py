class Solution(object):
    def numTimesAllBlue(self, light):
        """
        :type light: List[int]
        :rtype: int
        """
        '''
                        aux = [0] * len(l)
        ret = 0 # return value
        save = 0 # save state
        flag = 1
        # initial condition
        for i in range(0, len(l)):
            flag = 1
            aux[ l[i] ] = 1
            for j in range(save, i+1):
                if aux[j] == 0:
                    flag = 0
                    break
            if flag == 1:
                save = i
                ret+=1
        return ret
        '''
        l = [i-1 for i in light]
        m = -1
        ret = 0
        for i in range(len(l)):
            if l[i] > m:
                m = l[i]
            if m == i:
                ret+=1
        return ret
                                            