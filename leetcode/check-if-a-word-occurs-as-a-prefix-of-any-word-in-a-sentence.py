class Solution(object):
    def isPrefixOfWord(self, sentence, searchWord):
        """
        :type sentence: str
        :type searchWord: str
        :rtype: int
        """
        sentence = sentence.split()
        s = len(searchWord)
        for i in range(len(sentence)):
            # print(sentence[i])
            if searchWord in sentence[i][0:s]:
                                return i+1
        return -1
                        