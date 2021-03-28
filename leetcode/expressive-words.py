class Solution:
    def expressiveWords(self, S: str, words: List[str]) -> int:
        s = S
        ret = len(words)
        for i in words:
            if len(i) > len(s):
                ret-=1
                continue
            cur_s = 0 
            glob_s = 0
            flag = 0
            while (cur_s < len(i)):
                if (s[ glob_s ] != i[ cur_s ]):
                    ret -= 1 
                    flag = 1
                    break
                # print(s[glob_s], i[cur_s])
                cur_count = 1
                glob_count = 1
                # print('current ', cur_s, len(i))
                while (cur_s < len(i)-1 and i[ cur_s ] == i[cur_s + 1]):
                    cur_count += 1
                    cur_s += 1
                while (glob_s < len(s)-1 and s[ glob_s ] == s[ glob_s + 1 ]):
                    glob_count += 1
                    glob_s += 1
                # print(i[ cur_s], s[glob_s], cur_count, glob_count)
                if (glob_count >= 3 and cur_count < glob_count) or cur_count 
                    == glob_count:
                    # ok
                    cur_s +=1
                    glob_s += 1
                    # print(glob_s, cur_s)
                    continue
                else:
                    ret -= 1
                    flag = 1
                    break
            # print(cur_s, glob_s, len(s))
            if (glob_s < len(s) and flag == 0):
                # print(cur_s, glob_s, len(s))
                ret -=1
        return max(0, ret)