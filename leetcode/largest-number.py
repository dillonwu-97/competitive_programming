class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # something like counting sort?
        # maybe insertion
        # if a[i] > a[i-1]: return True / swap
        # else return False
        if len(nums) == 0: return ""
        nums = [str(i) for i in nums]
                # def comp(c, d):
        #     i = 0
        #     a = [int(j) for j in c]
        #     b = [int(j) for j in d]
        #     while (i < (min(len(a), len(b)))):
        #         if a[i] < b[i]:
        #             return True
        #         elif a[i] > b[i]:
        #             return False
        #         i+=1
        #     if len(a) > len(b):
        #         if int(c + d) > int(d + c): return False
        #         else: return True
        #         # if a[i] > b[0]: return False # no swap
        #         # else: return True # else swap
        #     elif len(b) > len(a):
        #         if int(c+d) > int(d+c): return False
        #         else: return True
        #         # if b[i] > a[0]: return True # no swap
        #         # else: return False # else swap            
        #     else:
        #         return False
                def comp(a, b):
            if int(a + b) >= int(b + a):
                return False
            else:
                return True
                def ins_sort(a):
            for i in range(1,len(a)):
                for j in range(i-1, -1, -1):
                    if comp(a[j] , a[j+1]):
                        temp = a[j]
                        a[j] = a[j+1]
                        a[j+1] = temp    
            return a
        a = ins_sort(nums)
        print(a)
        ans = "".join(a)
        if int(ans) == 0:
            return "0"
        else:
            return ans