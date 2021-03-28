# template<int MX> struct Trie {
#     int nex[MX][26], num = 0; // num is last node in trie
#     bool en[MX];
#     // change 2 to 26 for lowercase letters
    #     void ins(string x) {
#         int cur = 0;
#         aloop(t,x) {
#             if (!nex[cur][t-'a']) {
#               nex[cur][t-'a'] = ++num;
#               // print(cur, num);
#             }
#             // print("value is ", nex[cur][t-'a']);
#             cur = nex[cur][t-'a'];
#         }
#         en[cur] = 1;
#     }
# };
class WordDictionary:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.nex = [[0] * 26 for i in range(50000)]
        self.en = [0] * 50000
        self.num = 0
            def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        cur = 0
        for i in range(len(word)):
            index = ord(word[i]) - ord('a')
            # print(word[i], index)
            if (self.nex[cur][index] == 0):
                self.num +=1 
                self.nex[cur][index] = self.num
            cur = self.nex[cur][index]
        self.en[cur] = 1
        # print(self.en)
        # print("hi ", self.nex)
    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the 
            dot character '.' to represent any one letter.
        """
        # need to just do a recursive search here 
        index = ord(word[0]) - ord('a')
        cur = 0
        def solve(self, word, cur, letter):
            if (self.en[cur] == 1 and letter == len(word)): return True
            if letter >= len(word): return False
            # print(word, letter)
            index = ord(word[letter]) - ord('a')
            if word[letter] == '.': 
                v = False
                for i in range(len(self.nex[cur])):
                    if self.nex[cur][i]:
                        nexcur = self.nex[cur][i]
                        v |= solve(self, word, nexcur, letter + 1)
                return v
            elif self.nex[cur][index]:
                cur = self.nex[cur][index]
                return solve(self, word, cur, letter + 1)
            else:
                return False
                    return solve(self, word, 0, 0)
        # print(solve(self, None, None, None))
                            # cur = 0
        # for i in range(len(word)):
        #     print(cur)
        #     index = ord(word[i]) - ord('a')
        #     if index < 0:
        #         # recursively search if there is a '.'
        #         return recSearch(word[i:])
        #     if self.nex[cur][index]:
        #         cur = self.nex[cur][index]
        #     else:
        #         return False
        # if self.en[cur] == 1:
        #     return True
        # else:
        #     return False
        # Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)