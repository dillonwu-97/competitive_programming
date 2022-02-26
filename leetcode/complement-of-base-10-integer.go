func bitwiseComplement(n int) int {
    var s string
    s = strconv.FormatInt(int64(n), 2)
    // fmt.Println(s)
    var s_array[] string
        for _, v := range s {
        // fmt.Println(v)
        if string(v) == "1" {
            s_array = append(s_array, "0")
        } else {
            s_array = append(s_array, "1")
        }
    }
    var s2 string
    s2 = strings.Join(s_array[:], "")
        // Oops this is for reverse
    // for i := len(s)-1; i >= 0; i-- {
    //     s_array = append(s_array, string(s[i]))
    // }
    // s2 := strings.Join(s_array[:], "")
    // fmt.Println(s2)
        i,_:= strconv.ParseInt(s2, 2, 64)
    return int(i)
}