class Solution:
    def calculate(self, s: str) -> int:
        if len(s) == 1:
            return int(s)
        num = []
        sign = []
        i = 0
        current = ""
        while(i < len(s)):
            # print('i is: ', i)
            if s[i] == '*' or s[i]=='/' or s[i]=='-' or s[i]=='+':
                current = ""
                sign.append(s[i])
                i+=1
            elif s[i] == " ":
                current = ""
                i+=1
                continue
            else:
                while(i < len(s) and s[i].isnumeric() ):
                    current += s[i]
                    i+=1
                # i+= len(current)
                num.append(int(current))
        # print(num, sign)
        for i in range(len(sign)):
            if sign[i] == '*':
                num[i+1] *= num[i]
                num[i] = -1
            if sign[i] == '/':
                temp = num[i] // num[i+1]
                num[i+1] = temp
                num[i] = -1
        n = [i for i in num if i!=-1]
        if len(n) == 0:
            return 0
        total = n[0]
        track = 1
        for i in range (len(sign)):
            if sign[i] == '+':
                total += n[track]
                track+=1
            elif sign[i] == '-':
                total -= n[track]
                track +=1
        return total