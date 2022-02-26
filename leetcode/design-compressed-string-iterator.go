type StringIterator struct {
    count []int
    chars []string
}
func Constructor(compressedString string) StringIterator {
    count:= make([]int, 0)
    chars:= make([]string, 0)
        var complete_num string
    for i:=0; i!=len(compressedString); {
        // fmt.Println(compressedString[i])
        if compressedString[i] >= 65 {
            if i != 0 {
                temp, _ := strconv.Atoi(complete_num)
                count = append(count, temp)
            }
            chars = append(chars, string(compressedString[i]))
            complete_num = ""
        } else {
            complete_num += string(compressedString[i])
        }
        i ++
    }
        // last iteration 
    temp, _ := strconv.Atoi(complete_num)
    count = append(count, temp)
        // for k, v:= range compressedString {
    //     if k % 2 == 0 {
    //         chars = append(chars, string(v))
    //     } else {
    //         // fmt.Println(string(v))
    //         temp,_ := strconv.Atoi(string(v))
    //         count = append(count, temp)
    //     }
    // }
        return StringIterator {
        count: count,
        chars: chars,
    }
}
func (this *StringIterator) Next() byte {
    if len(this.count) == 0{
        return []byte(" ")[0]
    }
        this.count[0] --
    var ret string
    ret = this.chars[0]
    if this.count[0] == 0 {
        this.count = this.count[1:]
        this.chars = this.chars[1:]
    }
    // fmt.Println(ret, []byte(ret))
    return []byte(ret)[0]
}
func (this *StringIterator) HasNext() bool {
    if len(this.count) > 0 {
        return true
    } else {
        return false
    }
}
/**
 * Your StringIterator object will be instantiated and called as such:
 * obj := Constructor(compressedString);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */