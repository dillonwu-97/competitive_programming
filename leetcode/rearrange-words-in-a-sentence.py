class Solution:
    def arrangeWords(self, text: str) -> str:
        t = text.split(" ")
        t[0] = t[0].lower()
        t = sorted(t, key=len)
        s = " "
        t = s.join(t)
        t = t.capitalize()
        return t
    