# @param {Integer[]} nums
# @return {Integer[]}
def running_sum(nums)
#     ret = []
#     (1..nums.length).each do |i|
#         nums[i] += nums[i-1]
#     end
#     return nums
        (1..nums.length-1).each do |i|
        nums[i] += nums[i-1]
        # puts nums[i]
    end
    return nums
end