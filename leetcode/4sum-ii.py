from collections import Counter
from operator import add 
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        # H1 = Counter()
        # H2 = Counter()
        # H3 = Counter()
        # H4 = Counter()
        # for i in range(len(A)):
        #     H1[A[i]]+=1
        #     H2[B[i]]+=1
        #     H3[C[i]]+=1
        #     H4[D[i]]+=1
        # H12 = Counter()
        # for key1 in H1.keys():
        #     for key2 in H2.keys():
        #         H12[key1 + key2] += H1[key1] * H2[key2]
        # H23 = Counter()
        # for key12 in H12.keys():
        #     for key3 in H3.keys():
        #         H23[key12 + key3] += H12[key12] * H3[key3]
        # total = 0
        # for key4 in H4.keys():
        #     diff = 0 - key4
        #     if diff in H23.keys():
        #         total += H23[ diff ] * H4[key4]  
                # Try # 2:
        total = 0
        H1 = Counter()
        for i in range(len(A)):
            temp = map(add, A, B)
            for j in temp:
                H1[j] +=1
            A.append(A.pop(0))
        # print(H1)
        # H2 = Counter()
                for i in range(len(A)):
            temp = map(add, C, D)
            # print(C)
            for j in temp:
                if (0 - j) in H1:
                    total += H1[0 - j]
            C.append(C.pop(0))
        # print(H2)
        # for i in H1.keys():
        #     if 0 - i in H2:
        #         total += H1[i] * H2[0-i]
                        return total