class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.d = {}
        self.end = False
            def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
                current = self
        for i in range(len(word)):
            if word[i] not in current.d:
                new = Trie()
                current.d[word[i]] = new
                if i == len(word) - 1:
                    print("letter put into trie ", word[i])
                    current.d[word[i]].end = True
                current = new
            else:
                if len(word)-1 == i:
                    # print("letter put into trie 2", word[i])
                    current.d[word[i]].end = True
                current = current.d[word[i]]
        # print('current self ', self.end)
                def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        current = self
        for i in range(len(word)):
            if i == len(word) - 1:
                if word[i] in current.d and current.d[word[i]].end == True:
                    # print("true letter: ", word[i])
                    return True
                else:
                    return False
            elif word[i] in current.d:
                current = current.d[word[i]]
            else:
                return False
            def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given 
            prefix.
        """
        current = self
        for i in range(len(prefix)):
            if prefix[i] in current.d:
                current = current.d[prefix[i]]
            else:
                return False
        return True
        # Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)