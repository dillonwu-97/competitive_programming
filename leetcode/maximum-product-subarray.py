class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        A = nums
        B = A[::-1]
        for i in range(1, len(A)):
            # print('i-1 is : ', A[i-1])
            # print('or 1 is: ' , A[i-1] or 1)
            A[i] *= A[i - 1] or 1
            B[i] *= B[i - 1] or 1
        # print(A)
        # print(B)
        # print(A+B)
        return max(A + B)
                        # def solve(nums):
        #     if len(nums) == 0:
        #         return 0
        #     if len(nums) == 1:
        #         return nums[0]
        #     m = 0 # current max
        #     current = 0 # current num
        #     neg = 0
        #     zf = 0
        #     save_state = 0
        #     # zcount = 0 # for debugging
        #     for i in range(len(nums)):
        #         # if zcount == 1:
        #             # print(m, current, neg, zf, save_state)
        #         if nums[i] == 0:
        #             # zcount +=1
        #             # reset
        #             neg = 0
        #             # print(nums[i], current)
        #             if current > m:
        #                 m = current
        #             current = 0
        #             zf = 1
        #             save_state=0
        #         elif nums[i] < 0 and neg == 0:
        #             neg = nums[i]
        #             if current > m:
        #                 m = current
        #             save_state = current
        #             current = 0
        #         elif nums[i] < 0 and neg!= 0:
        #             if current == 0: current = 1
        #             if zf == 0:
        #                 if save_state == 0: save_state = 1
        #                 current = current * neg * nums[i] * save_state
        #             else: 
        #                 current *= neg * nums[i]
        #             neg = 0
        #         else:
        #             if current == 0:
        #                 current = 1
        #             zf = 0
        #             current *= nums[i]
        #     if current > m:
        #         m = current
        #     return m
        # # return (solve(nums))
        # return (max(solve(nums), solve(nums[::-1])))
        # #[-2,0,-1,0,0,0,1,0,0,0,3,2,0,0,-1,-100,0]  <-- need 0 flag for this
            ?t