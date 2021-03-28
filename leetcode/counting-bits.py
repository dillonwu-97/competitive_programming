class Solution:
    def countBits(self, num: int) -> List[int]:
        def add(a, count):
            i = len(a)-1
            while (a[i] == 1):
                a[i] = 0
                count -=1
                i-=1
            a[i] = 1
            return count + 1
                        bitmap = [0] * (len(bin(num))-1)
        ret = [0]
        c = 0
        for i in range(num):
            c = add(bitmap, c)
            ret.append(c)
        return ret
                