func sortSentence(s string) string {
    ss:= strings.Split(s, " ")
    ret := make([]string, len(ss))
    // fmt.Println(ss)
    // var index int
    for i:= 0; i < len(ss); i++ {
        index, _ := strconv.Atoi(string(ss[i][len(ss[i])-1]))
        temp := ss[i][:len(ss[i])-1]
        // fmt.Println(index, err, temp)
        ret[index-1] = temp
    }
    return strings.Join(ret," ")
}