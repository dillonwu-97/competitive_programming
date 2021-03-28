from collections import Counter
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        # find number in the list in the right pos
        # find number in the list in the wrong pos
        dguess = Counter()
        dsecret = Counter()
        bulls = 0
                for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                dsecret[ secret[i] ] += 1
                dguess [ guess[i] ] += 1
                k = set(list(dguess.keys()) + list(dsecret.keys()))
        cows = 0
        for i in k:
            if i in dsecret and i in dguess:
                cows += min(dsecret[i], dguess[i])
                return str(bulls) + "A" + str(cows) + "B"