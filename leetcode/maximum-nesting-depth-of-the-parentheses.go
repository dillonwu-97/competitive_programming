func maxDepth(s string) int {
    var ret int = 0
    var m int = 0;
    for _, i := range s {
        if string(i) == "(" {
            ret ++;
        } else if string(i) == ")" {
            ret --;
        }
        if ret > m {
            m = ret;
        }
    }
    return m;
}