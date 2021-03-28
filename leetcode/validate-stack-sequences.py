class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> 
        bool:
        n = []
        j = 0
        i = 0
        while(j != len(popped)):
            # print(i, n)
            if len(n) > 0 and n[len(n)-1] == popped[j]:
                n.pop()
                j+=1
            elif i == len(pushed):
                temp = n.pop()
                if temp != popped[j]:
                    return False
                j+=1
            elif pushed[i]== popped[j]:
                j+=1
                i+=1
            else:
                n.append(pushed[i])
                i+=1
        return True
            