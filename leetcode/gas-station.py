class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if len(gas) == 0:
            return -1
        total = [(gas[i], cost[i], i) for i in range(len(gas))]
        if sum(gas) < sum(cost):
            return -1
        sg = 0#sum gas, sum cost
        sc =0
        repeat_i = -1
        while(len(total)!=0):
            # print(total)
            curr = total.pop(0)
            g,c = curr[0], curr[1]
            # if repeat_i == curr[2]:
            #     # print(repeat_i, curr[2])
            #     return -1
            if sg == 0 and sc == 0:
                if g >= c:
                    # repeat_i = curr[2]
                    repeat_i = curr[2]
                    sg += g
                    sc += c
                else:
                    total.append((g,c,curr[2]))
            else:
                if sg + g >= sc + c:
                    sg+=g
                    sc+=c
                else : # if g < c OR sg +g < sc + c
                    total.append((sg,sc, repeat_i))
                    total.append((g, c, curr[2]))
                    sg = 0
                    sc = 0
                    # repeat_i = curr[2]
        return repeat_i
                                    