class LRUCache:
    def __init__(self, capacity: int):
        self.o = OrderedDict()
        self.curr = 0
        self.capacity = capacity
            def get(self, key: int) -> int:
        if key in self.o:
            # update; least recently used is stored at index 0 of self.a
            temp = self.o[key]
            del self.o[key]
            self.o[key] = temp
            return temp
        else:
            return -1
            def put(self, key: int, value: int) -> None:
        if key in self.o:
            del self.o[key]
            self.o[key] = value
        else:
            if self.curr == self.capacity:
                k = next(iter(self.o))
                del self.o[k]
                self.curr-=1
            self.o[key]=value
            self.curr+=1
        # Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)