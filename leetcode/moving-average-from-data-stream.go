// [-----]
//  ^ <-- pointer to the current element to delete, should be pos % size
// need to keep track of current count
type MovingAverage struct {
    // count int
    // cur int // pointer to the element to delete
    // size int // size of list
    // sum int // total sum
    // nums[] int
    size int
    sum int
    nums[] int
        }
func Constructor(size int) MovingAverage {
    // a:=make([]int, size)
    // m:=MovingAverage{count:0, cur:0, size:size, sum:0, nums:a}
    // return m
    return MovingAverage{
        size: size,
        sum: 0,
        nums: []int{},
    }
}
func (this *MovingAverage) Next(val int) float64 {
    this.nums = append(this.nums, val)
    this.sum += val
    if len(this.nums) > this.size {
        this.sum -= this.nums[0]
        this.nums = this.nums[1:]
    }
    return float64(this.sum) / float64(len(this.nums))
//     this.count ++
//     if this.count > this.size {
//         this.count -- 
//         this.sum -= this.nums[ this.cur ]
//         this.nums[ this.cur ] = val
//         this.cur ++
//         this.cur %= this.size
        //     } else {
//         this.nums[ this.count -1] = val
//     }
//     // fmt.Println(this.nums)
//     this.sum += val
//     return float64(this.sum) / float64(this.count)
    // this.count++;
    // if (this.count > this.size) {
    //     this.count--
    //     this.sum
    // }
}
/**
 * Your MovingAverage object will be instantiated and called as such:
 * obj := Constructor(size);
 * param_1 := obj.Next(val);
 */