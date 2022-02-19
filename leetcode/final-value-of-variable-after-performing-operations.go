func finalValueAfterOperations(operations []string) int {
    var a int = 0
    for i:= 0; i < len(operations); i++ {
        // fmt.Println(operations[i][0])
        if string(operations[i][0]) == "+" || string(operations[i][2]) == "+" {
            a++
        } else {
            a--
        }
    }
    return a
}