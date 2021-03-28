class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
                # n^2 alg
        ret = 0
        while(len(arr) > 1):
            m = 999999999
            index = -1
            for i in range(len(arr)):
                if arr[i] < m:
                    m = arr[i]
                    index = i
            # remove / change array
            if index + 1 < len(arr) and index - 1 >= 0:
                if arr[index + 1] < arr[index - 1]:
                    ret += arr[index + 1] * arr[index]
                    arr[index + 1] = max(arr[index], arr[index + 1])
                    arr = arr[:index] + arr[index+1:]
                else:
                    ret += arr[index - 1] * arr[index]
                    arr[index-1] = max(arr[index], arr[index - 1])
                    arr = arr[:index] + arr[index+1:]
            elif index == len(arr)-1:
                ret += arr[index - 1] * arr[index]
                arr[index-1] = max(arr[index], arr[index - 1])
                arr = arr[:index]
            elif index == 0:
                ret += arr[index + 1] * arr[index]
                arr[index + 1] = max(arr[index], arr[index + 1])
                arr = arr[index+1:]
        return ret
                                                                            