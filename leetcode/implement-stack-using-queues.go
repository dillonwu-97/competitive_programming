type MyStack struct {
    q1 [] int
    q2 [] int
}
func Constructor() MyStack {
    return MyStack{
        q1:[]int{},
        q2:[]int{},
    }
}
func (this *MyStack) Push(x int)  {
    if len(this.q1) > len(this.q2) {
        this.q1 = append(this.q1, x)    
    } else {
        this.q2 = append(this.q2, x)
    }
    }
func (this *MyStack) Pop() int {
    var p []int
    var o []int
    if len(this.q1) > len(this.q2) {
        p = this.q1
        o = this.q2
    } else {
        // fmt.Println("HI")
        p = this.q2
        o = this.q1
    }
    // fmt.Println(o)
    // fmt.Println("p is ", p, this.q1, this.q2)
    for i:= 0; i < len(p)-1; i++ {
        o = append(o, p[i])
    }
    p = p[len(p) - 1:]
    var ret int
        ret = p[0]
    p = p[1:]
    // fmt.Println("o is ", o)
    // fmt.Println("p is ", p)
    this.q1 = p
    this.q2 = o
    return ret
}
func (this *MyStack) Top() int {
    var p []int
    if len(this.q1) > len(this.q2) {
        p = this.q1
    } else {
        p = this.q2
    }
    return p[len(p) - 1]
        }
func (this *MyStack) Empty() bool {
    if (len(this.q1) > 0) || (len(this.q2) > 0) {
        return false
    } else {
        return true
    }
}
/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */