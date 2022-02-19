func countKDifference(nums []int, k int) int {
        m:= make(map[int]int)
    var ret int = 0;
    for i:= 0; i < len(nums); i++ {
        // if val, ok := dict["foo"]; ok {
    //do something here
        if val, ok := m[nums[i]]; ok {
            // fmt.Println(nums[i], val);
            ret+=val;
        }
        m[nums[i] + k] ++;
        m[nums[i] - k] ++;
        }
    return ret;
}