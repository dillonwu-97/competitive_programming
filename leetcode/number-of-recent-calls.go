type RecentCounter struct {
    // [ ] <- array of times
    // when ping is called, loop over the times and remove any that are
    // not within the range
    // could do binary search to make it faster
    a[] int    
}
func Constructor() RecentCounter {
    return RecentCounter{
        a: []int{},
    } 
}
func (this *RecentCounter) Ping(t int) int {
    this.a = append(this.a, t)
    var cur int = 0
    for i:=0; i < len(this.a); i++ {
        if this.a[i] >= t - 3000 {
            cur = i
            break
        }
    }
    this.a = this.a[cur:]
    return len(this.a)
}
/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */