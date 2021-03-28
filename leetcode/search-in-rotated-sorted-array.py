class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binary_search(alist, start, end, key):
            """Search key in alist[start... end - 1]."""
            if not start < end:
                return -1
            mid = (start + end)//2
            if alist[mid] < key:
                return binary_search(alist, mid + 1, end, key)
            elif alist[mid] > key:
                return binary_search(alist, start, mid, key)
            else:
                return mid
        if len(nums) == 0:
            return -1
        elif len(nums) == 1:
            if nums[0] == target:
                return 0
            else:
                return -1
        def bst_mod (alist, start, end, key):
            # print(start, end)
            if start == end - 1:
                if alist[start] == key:
                    return start
                elif alist[end] == key:
                    return end
                else:
                    return -1
            mid = (start + end) // 2
            # print(start, end, mid)
            if alist[mid] == key:
                return mid
            elif alist[mid] > alist[start] and alist[mid] > alist[end]:
                if alist[start] <= key < alist[mid]:
                    return bst_mod(alist, start, mid, key)
                else:
                    return bst_mod(alist, mid+1, end, key)
            elif alist[end] > alist[mid] and alist[mid] > alist[start]:
                if alist[mid] < key:
                    return bst_mod(alist, mid+1, end, key)
                else:
                    return bst_mod(alist, start, mid, key)
            elif alist[start] > alist[mid] and alist[end] > alist[mid]:
                if alist[mid] < key <= alist[end]:
                    return bst_mod(alist, mid+1, end,key)
                else:
                    return bst_mod(alist, start, mid, key)
            else:
                return -1
                return bst_mod(nums, 0, len(nums)-1, target)
            