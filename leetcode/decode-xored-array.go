func decode(encoded []int, first int) []int {
    var ret[] int
    ret = append(ret, first)
    for i:= 0; i < len(encoded); i++ {
        ret = append(ret, encoded[i] ^ ret[i])
    }
    return ret
}