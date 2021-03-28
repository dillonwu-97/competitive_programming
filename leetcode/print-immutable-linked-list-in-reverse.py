# """
# This is the ImmutableListNode's API interface.
# You should not implement it, or speculate about its implementation.
# """
# class ImmutableListNode:
#     def printValue(self) -> None: # print the value of this node.
#     def getNext(self) -> 'ImmutableListNode': # return the next node.
class Solution:
    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
        l = []
        while(head != None):
            l.append(head)
            head = head.getNext()
        l.reverse()
        for i, j in enumerate(l):
            j.printValue()
        