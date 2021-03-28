class Solution(object):
    def getStrongest(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        arr.sort()
        m = arr [ (len(arr) -1) / 2]
        abs_a = []
        ret = []
        h = {}
        arr.sort( reverse = True)
        for i in range(len(arr)):
                        temp = abs(arr[i] - m)
            if temp in h:
                h[temp].append(arr[i])
            else:
                h[temp] = [arr[i]]
        for key in sorted(h.keys(), reverse=True):
            temp = h[key]
            count = 0
            while (k!= 0 and count != len(temp)):
                ret.append(temp[count])
                count +=1
                k-=1
                    return ret
        