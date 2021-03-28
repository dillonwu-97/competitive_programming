# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        a = []
        b = []
        while (l1!= None):
            a.append(str(l1.val))
            l1 = l1.next
        while (l2!=None):
            b.append(str(l2.val))
            l2 =l2.next
        c = str(int("".join(a)) + int("".join(b)))
        ret = [0] * len(c)
        for i in range(len(c)):
            ret[i] = ListNode(val=int(c[i]))
            if i != 0:
                ret[i-1].next = ret[i]
        return ret[0]
                    