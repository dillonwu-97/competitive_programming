class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # definitely a stack
        if len(tokens) == 0:
            return 0
        op = ["*", "/", "+", "-"]
        stack = []
        for i in range(len(tokens)):
            if tokens[i] != op[0] and tokens[i] != op[1] and tokens[i] != 
                op[2] and tokens[i] != op[3]:
                stack.append(int(tokens[i]))
            else:
                a = stack.pop()
                b = stack.pop()
                if tokens[i] == "+":
                    stack.append(a+b)
                elif tokens[i] == "-":
                    stack.append(b-a)
                elif tokens[i] == "/":
                    temp = abs(b) // abs(a)
                    if b <0 and a > 0 or b >0 and a <0:
                        temp*=-1
                        stack.append(temp)
                    else:
                        stack.append(temp)
                elif tokens[i] == "*":
                    stack.append(a*b)
                # print(a, b, stack)
        # print(stack)
        return stack[0]