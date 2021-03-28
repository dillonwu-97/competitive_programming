// import ("math")
func numIdenticalPairs(nums []int) int {
    v := make(map[int]int)
    for i:= 0; i < len(nums); i++ {
        // fmt.Println(nums[i])
        v[nums[i]] += 1
    }
    ret := 0
    for _, element := range v {
        // fmt.Println(key, element)
        ret += (element -1) * element / 2
    }
    return ret
}
// import ("math")
// func calculateTime(keyboard string, word string) int {
    //     v := make(map[string]int)
//     for i:=0; i < len(keyboard); i++ {
//         v[string(keyboard[i])] = i
//     }
//     // fmt.Println(v)
    //     ret := 0
//     prev:= 0
//     current:= -1
//     for x:= 0; x < len(word); x++ {
//         // fmt.Println(string(word[x]))
//         current = v[string(word[x])]
//         // fmt.Println(current, prev, int64(math.Abs(float64(current - prev
    ))))
//         ret += int(math.Abs(float64(current - prev)))
//         prev = current
//     }
//     return ret
// }