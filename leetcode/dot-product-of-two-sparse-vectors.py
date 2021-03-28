class SparseVector:
    def __init__(self, nums: List[int]):
        self.v = nums
    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        # print(self.v)
        # print(vec.v)
        t = 0
        for i, j in enumerate(vec.v):
            t += vec.v[i] * self.v[i]
        return t
        # Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)