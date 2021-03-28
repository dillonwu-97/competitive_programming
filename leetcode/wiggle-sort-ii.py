class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # nums.sort()
        # if len(nums) % 2 == 0:
        #     l = len(nums) // 2
        #     # print(nums[::2], nums[l-1::-1])
        #     nums[::2], nums[1::2] = nums[l-1::-1], nums[:l-1:-1]
        # else:
        #     l = len(nums) // 2
        #     nums[::2], nums[1::2] = nums[l::-1], nums[:l:-1]
        #     # nums[::2], nums[1::2] = nums[:l], nums[l:] 
                        def swap(a, x, y):
            temp = a[x]
            a[x] = a[y]
            a[y] = temp
                # nlogn for sort, n for copy of the array 
        # make it so that u start from middle -> start for even indices, and 
            end -> middle for odd indices
        a = nums.copy()
        a.sort()
        if len(a) % 2 == 0:
            curr = 1
            for i in range(0, len(nums), 2):
                nums[i] =  a[len(a) // 2 - curr]
                nums[i+1] = a[len(a) - curr]
                curr +=1
        else:
            curr = len(nums) // 2
            for i in range(0, len(nums),2):
                nums[i] = a[curr]
                curr -= 1
            curr = len(nums) - 1
            for i in range(1, len(nums), 2):
                nums[i] = a[curr]
                curr -= 1
                                    