class Solution:
    def getSum(self, a: int, b: int) -> int:
        def rev (y):
            total = ""
            for i in range(len(y)):
                if y[i] == "0":
                    total += "1"
                elif y[i] == "1":
                    total += "0"
            return total
        def add (x, y):
            carry = 0
            total = ""
            for i in range(len(y)):
                temp = int(x[i]) + int(y[i]) + carry
                # debug.append(str(carry))
                # debug2.append(str(temp))
                if temp ==2:
                    carry = 1
                    total+= "0"
                elif temp == 3:
                    total += "1"
                    carry = 1
                else:
                    carry = 0
                    total += str(temp)
            if carry == 1:
                total += "1"
            total = total[::-1]
            return total
                x = bin(abs(a))[2:]
        y = bin(abs(b))[2:]
        if len(x) > len(y):
            y = "".join(["0"] * (len(x) - len(y))) + y
        else:
            x = "".join(["0"] * (len(y) - len(x))) + x
        x = x[::-1]
        y = y[::-1]
        # Addition
        if (a >= 0 and b >= 0) or (a <= 0 and b <= 0):
            total = add(x, y)
            if (a < 0 or b < 0):
                ret = int(total, 2) * -1
            else: 
                ret = int(total, 2)
            return ret
        # subtraction
        else:
            if (abs(b) > abs(a) and a < b):
                x, y = y, x
            if (abs(b) > abs(a) and a > b):
                x, y = y, x
            # print(x)
            # print(y)
            total = rev(y) # bit flip 
            temp = "1" + "".join(["0"] * (len(x) - 1)) # get twos complement
            total = add(total, temp)
            # print('2s complement :' + total) # <== two's complement
            total = total[::-1]
            total = add(total, x)[1:]
            ret = int(total, 2)
            if a < b and abs(a) > abs(b) or abs(b) > abs(a) and a > b:
                ret*=-1
                                                    return ret
                