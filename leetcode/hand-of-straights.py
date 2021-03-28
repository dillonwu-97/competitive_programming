class Solution(object):
    def isNStraightHand(self, hand, W):
        """
        :type hand: List[int]
        :type W: int
        :rtype: bool
        """
        if len(hand) % W != 0:
            return False
        elif W ==1:
            return True
        d = {}
        hand.sort()
                for i in range(len(hand)):
            x = hand[i]
            if x-1 in d and len(d[x-1]) > 0:
                temp = d[x-1][0] + 1
                d[x-1].pop(0)
                if temp != W-1:
                    if x in d:
                        d[x].append(temp)
                    else:
                        d[x] = [temp]
            elif x not in d:
                d[x] = [0]
            else:
                d[x].append(0)
            # print(d)
                for i in d.keys():
            if len(d[i]) != 0:
                return False
                            return True