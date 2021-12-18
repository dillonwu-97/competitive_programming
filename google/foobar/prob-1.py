def solution(x, y):
    if (len(x) > len(y)):
        a = set(x)
        b = set(y)
    else:
        a = set(y)
        b = set(x)
    c = a - b
    print(list(c)[0])
    return 0


solution([1,2,3],[1,2,3,4])
