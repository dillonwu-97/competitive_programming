func xorOperation(n int, start int) int {
    var i int = start
    var ret int = 0
    for i < (n * 2 + start) {
        // fmt.Println(i)
        ret ^= i
        i+=2
    }
    return ret
}