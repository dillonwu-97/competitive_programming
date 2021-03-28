class Solution(object):
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        d = {}
        for i in deadends:
            d[i] = 1
        if "0000" in d:
            return -1
        q = []
        q.append(("0000", 0))
        visited = {}
        while(len(q) != 0):
            out = q.pop(0)
            n = out[0]
            count = out[1]
            # print(n, count)
            if n == target:
                return count
            for i in range(len(n)):
                temp = int(n[i])
                up = temp+1
                down = temp-1
                if up == 10: up = 0
                if down == -1: down = 9
                up_str = n[:i] + str(up) + n[i+1:]
                down_str = n[:i] + str(down) + n[i+1:]
                if up_str not in visited and up_str not in d:
                    q.append((up_str, count+1))
                    visited[up_str] = 1
                if down_str not in visited and down_str not in d: 
                    q.append((down_str, count+1))
                    visited[down_str] = 1
        return -1
                                    