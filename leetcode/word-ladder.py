class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) 
        -> int:
        d = {}
        for i in wordList:
            d[i] = 0
        q = []
        visited = {}
        q.append((beginWord,0)) # beginword, and number visited
        while (len(q) > 0): 
            out = q.pop(0)
            w = out[0]
            count = out[1]
            # print(w, count)
            if w == endWord:
                return count + 1
            else:
                 for i in range(len(w)):
                    for letter in string.ascii_lowercase:
                        temp = w[0:i] + letter + w[i+1:]
                        if temp in d and temp not in visited:
                            visited[temp] = count
                            q.append((temp,count + 1))
        return 0
            