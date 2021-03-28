# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        l = []
        track1 = l1
        track2 = l2
        if (l1 == None): return l2
        if (l2 == None): return l1
        while(track1 and track2):
            # print(track1.val, track2.val)
            if track2 == None or track1.val < track2.val:
                l.append(track1)
                track1 = track1.next
            elif track2.val <= track1.val or track1 == None:
                l.append(track2)
                track2 = track2.next
        for i in range(1,len(l)):
            l[i-1].next = l[i]
        if track2 != None:
            l[-1].next = track2
        if track1 != None:
            l[-1].next = track1
        return l[0]
#         track1 = l1
#         track2 = l2
#         while():
#             if track1.val < track2.val and track1.next.val > track2.val:
#                 track1.next = track2
#                 track2.next = track1.next
            