import random
class RandomizedSet(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.l = {}
            def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already 
            contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.l:
            return False
        else:
            self.l[val] = 1
            return True
    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the 
            specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.l:
            del self.l[val]
            return True
        else:
            return False
    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        # print(self.l.keys())
        return random.choice(self.l.keys())
                # Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()