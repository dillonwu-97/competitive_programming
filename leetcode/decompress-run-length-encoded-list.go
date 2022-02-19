func decompressRLElist(nums []int) []int {
    var ret[] int
    var f int
    var s int
    for i:= 0; i < len(nums); i+= 2 {
        f = nums[i]
        s = nums[i+1]
        for j:= 0; j < f; j++ {
            ret = append(ret, s)    
        }
    }
    return ret
}