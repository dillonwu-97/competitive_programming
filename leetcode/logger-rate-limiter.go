type Logger struct {
        words map[string]int
    }
func Constructor() Logger {
    return Logger{
        words: map[string]int{},
    }
}
func (this *Logger) ShouldPrintMessage(timestamp int, message string) bool {
    if val, ok := this.words[message]; ok {
        // fmt.Println(val, timestamp, this.words[message])
        if timestamp - val >= 10 {
            this.words[message] = timestamp
            return true
        } else {
            return false
        }
    } 
    this.words[message] = timestamp
    return true
}
/**
 * Your Logger object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.ShouldPrintMessage(timestamp,message);
 */