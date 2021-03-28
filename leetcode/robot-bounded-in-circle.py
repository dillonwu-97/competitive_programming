class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
                d = [0,0] # N/S E/W
        direction = 0 # %4
        for i in range(4):
            for i in range(len(instructions)):
                if instructions[i] == 'G':
                    if direction == 0:
                        d[0] += 1
                    if direction == 1:
                        d[1] += 1
                    if direction == 2:
                        d[0] -=1
                    if direction == 3:
                        d[1] -= 1
                if instructions[i] == 'L':
                    direction -=1
                    direction %= 4
                if instructions[i] == 'R':
                    direction += 1
                    direction %=4
            if d[0] == 0 and d[1] == 0:
                return True
        return False
                                                                