func targetIndices(nums []int, target int) []int {
        sort.Ints(nums);
        var ret[] int;
        for index, b := range nums {
            if b == target {
                ret = append(ret, index)
            }
        }
        return ret;
}