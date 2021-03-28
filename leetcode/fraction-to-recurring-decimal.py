from collections import Counter
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        on = numerator
        od = denominator
        n = abs(numerator)
        d = abs(denominator)
        if d == 0 or n == 0:
            return "0"
                        # if d is prime factor of 2 or 5 => terminating
        # else non terminating
        # if d > n and(d == 1 or d % 2 == 0 or d % 5 == 0): 
        #     return str(n/d)
        # elif n > d and n % d == 0:
        #     return str(n//d)
        if on % od == 0:
            return str(on//od)
        else:
            # how to know if repeating? 
            # do long division and store the remainders
            # test with 49/12
            num = str(n//d) + '.'
            seen = Counter()
            repeat = ""
            n%=d
            flag = 0
            count = 0
            while(n % d != 0):
                n *=10
                if n not in seen:
                    # print(n, repeat)
                    seen[n] = count
                    count +=1
                    repeat +=str(n//d)
                    n%=d
                else:
                    count = seen[n]
                    flag = 1
                    break
            if flag == 1:
                # this means that there was a repeat so include parenthesis
                num = num + repeat[:count] + '(' + repeat[count:] + ')'
            else:
                num+=repeat
            if od < 0 and on > 0 or on < 0 and od > 0:
                num = '-' + num
                            return num
            