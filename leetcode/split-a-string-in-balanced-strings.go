func balancedStringSplit(s string) int {
    var ret int = 0
    var cur int = 0
    for i:= 0; i < len(s); i++ {
        if string(s[i]) == "R" {
            cur ++
        } else {
            cur --
        }
        if (cur == 0) {
            ret ++
        }
    }
    return ret
}