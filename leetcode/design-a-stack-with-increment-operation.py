class CustomStack(object):
    def __init__(self, maxSize):
        """
        :type maxSize: int
        """
        self.maxSize = maxSize
        self.count = 0
        self.list = []
            def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if (self.count < self.maxSize):
            self.count +=1
            self.list.append(x)
                    def pop(self):
        """
        :rtype: int
        """
        # print('hi' + str(self.list))
        if len(self.list) > 0:
            val = self.list.pop(-1)
            self.count-=1
        else: 
            val = -1
        # print('hello' + str(self.list))
        return val
                    def increment(self, k, val):
        """
        :type k: int
        :type val: int
        :rtype: None
        """
        # print(self.list)
        if k > len(self.list):
            k = len(self.list)
        for i in range(k):
            self.list[i]+=val
        # print(self.list)
        # Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)