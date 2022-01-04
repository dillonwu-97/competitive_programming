/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getDecimalValue(head *ListNode) int {
    var ret string
    for head != nil {
        ret += strconv.Itoa(head.Val)
        head = head.Next
    }
    // fmt.Println(ret)
    ret2, _ := strconv.ParseInt(ret, 2, 64)
    ret3 := int(ret2)
    return ret3
}