class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # binary search alg modified 
        # find low
        if len(nums) == 0:
            return [-1,-1]
        if len(nums) == 1:
            if nums[0] == target:
                return [0,0]
            else:
                return [-1,-1]
        def find_start (alist, start, end, key):
            if start > end: 
                return -1
            elif alist[start] == key:
                return start
            if start == end -1:
                if alist[start] == key:
                    return start
                elif alist[end] == key:
                    return end
                else:
                    return -1
            mid = (start + end) // 2
            # print(start, end, mid, alist[mid])
            if alist[mid] >= key:
                return find_start(alist,start, mid, key)
            else:
                return find_start(alist, mid, end, key)
                def find_end (alist, start, end, key):
            if start > end: 
                return -1
            elif alist[end] == key:
                return end
            if start == end -1:
                if alist[end] == key:
                    return end
                elif alist[start] == key:
                    return start
                else:
                    return -1
            mid = (start + end) // 2
            # print(start, end, mid, alist[mid])
            if alist[mid] <= key:
                return find_end(alist, mid, end, key)
            else:
                return find_end(alist, start, mid, key)
                a =(find_start(nums, 0, len(nums)-1, target))
        b = (find_end(nums, 0, len(nums)-1, target))
        return [a,b]