func solve(command string) string {
    var temp string= strings.Replace(command, "(al)", "al", -1)
    temp = strings.Replace(temp, "()", "o", -1)
    return temp
}
func interpret(command string) string {
    return solve(command)
}