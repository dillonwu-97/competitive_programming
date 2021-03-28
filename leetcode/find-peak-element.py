class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def binary_search(alist, start, end):
            """Search key in alist[start... end - 1]."""
            if not start < end:
                return start
            mid = (start + end)//2
            if alist[mid] < alist[mid +1]:
                return binary_search(alist, mid + 1, end)
            elif alist[mid] < alist [mid - 1]:
                return binary_search(alist, start, mid)
            else:
                return mid
                return binary_search(nums, 0, len(nums)-1)