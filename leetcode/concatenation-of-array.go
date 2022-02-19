func getConcatenation(nums []int) []int {
    var a int = len(nums)
    for i:= 0; i<a; i++ {
        // fmt.Println(nums[i])
        nums = append(nums, nums[i])
    }
    return nums
}