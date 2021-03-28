func restoreString(s string, indices []int) string {
    ret := make([]byte, len(s))
    for i, j := range(indices) {
        // j is the value at the index
        ret[j] = s[i]
    }
    return string(ret)
}