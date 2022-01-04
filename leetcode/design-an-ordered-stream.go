type OrderedStream struct {
    s [] string
    size int
    cur int // current pointer
}
func Constructor(n int) OrderedStream {
    s:= make([]string, n)
    o := OrderedStream{cur: 0, size: n, s:s};
    return o;
}
func (this *OrderedStream) Insert(idKey int, value string) []string {
    this.s[idKey-1] = value
    var m int = this.size;
    // fmt.Println("idKey is ", idKey-1, "cur is ", this.cur)
    if (idKey - 1 == this.cur) {
        for k:= 0; k < this.size; k++ {
                        if this.s[k] == "" {
                m = k
                break
            }
        }
        ret := this.s[this.cur:m]
        // fmt.Println("ret is ", ret, "m is: ", m)
        this.cur = m
        return ret
    } 
    ret := make([]string, 0)
    return ret
        }
/**
 * Your OrderedStream object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Insert(idKey,value);
 */