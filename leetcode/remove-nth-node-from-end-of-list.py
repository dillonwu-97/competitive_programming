# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        l = []
        while (head!= None):
            l.append(head)
            head = head.next;
        if len(l) == 1:
            return None
        pos = len(l) - n
        if pos == 0:
            return l[1]
        if n == 1:
            l[pos-1].next = None
            return l[0]
        l[pos-1].next = l[pos+1]
        return l[0]