func countMatches(items [][]string, ruleKey string, ruleValue string) int {
    var index int
    if ruleKey == "type" {
        index = 0
    } else if ruleKey == "color" {
        index = 1
    } else {
        index = 2
    }
    var ret int = 0
    for i:= 0; i < len(items); i++ {
        if items[i][index] == ruleValue {
            ret ++
        }
    }
    return ret
}