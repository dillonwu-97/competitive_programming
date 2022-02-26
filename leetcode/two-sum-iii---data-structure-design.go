type TwoSum struct {
    d map[int]int
    a []int
}
func Constructor() TwoSum {
        return TwoSum{
        d: map[int]int{},
        a: []int{},
    }
}
func (this *TwoSum) Add(number int)  {
    if _, ok := this.d[number]; !ok {
        this.d[number] = 1
    } else {
        this.d[number] ++
    }
        this.a = append(this.a, number)
}
func (this *TwoSum) Find(value int) bool {
        for _,k := range this.a {
        // fmt.Println("hi", k, v)
        if val, ok := this.d[value - k]; ok {
            if value -k == k {
                if val >= 2 {
                    // fmt.Println("inside val >= 2")
                    return true
                } else {
                    continue
                }
            } else {
                // fmt.Println(value -k, k)
                return true
            }
        } 
    }
    return false
}
/**
 * Your TwoSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(number);
 * param_2 := obj.Find(value);
 */