func defangIPaddr(address string) string {
    ret := ""
    for index, value := range(address) {
        if (address[index] == '.') {
            ret += "[.]"
        } else {
            ret += string(value)
        }
    }
    return ret
}