class BrowserHistory(object):
    def __init__(self, homepage):
        """
        :type homepage: str
        """
        self.visited = [homepage]
        self.current = 0
            def visit(self, url):
        """
        :type url: str
        :rtype: None
        """
        if len(self.visited)-1 == self.current:
            self.visited.append(url)
        else:
            # print('current is ', self.visited[self.current])
            self.visited [self.current + 1] = url
            self.current +=1
            self.visited = self.visited [:self.current+1]
        self.current = len(self.visited) -1
            def back(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        if steps > self.current:
            self.current = 0
            return self.visited[0]
        else:
            self.current -= steps
            # print('hi')
            # print(self.visited)
            # print(self.current)
            return self.visited [ self.current ]
                    def forward(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        if len(self.visited) - self.current-1  < steps:
            self.current = len(self.visited) -1
            return self.visited[ -1]
        else:
            # print(steps)
            # print(self.current)
            # print(self.visited)
            self.current += steps
            return self.visited [ self.current ]
                #[null,null,null,null,"facebook.com","google.com","facebook.com",null
            ,"linkedin.com","google.com","leetcode.com"]
        #[null,null,null,null,"facebook.com","google.com","facebook.com",null
            ,"linkedin.com","google.com","leetcode.com"]
# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)