class NumArray:
    def __init__(self, nums: List[int]):
        self.nums = [0] * (len(nums))
        if len(nums) > 0:
            self.nums[0] = nums[0]
        for i in range(1,len(nums)):
            self.nums[i] = self.nums[i-1] + nums[i]
        self.nums = [0] + self.nums
            def sumRange(self, i: int, j: int) -> int:
        # print(self.nums)
        return self.nums[j+1] - self.nums[i]
        # Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)