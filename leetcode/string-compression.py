class Solution:
    def compress(self, chars: List[str]) -> int:
        count = 1
        j = 0
        track = 0 # keep track of write pointer
        while (j < len(chars)):
            current_char = chars[j]
            count = 0
            while (j < len(chars) and chars[j] == current_char):
                count += 1
                j+=1    
            # print(count, chars)
                        # replacing list
            k = 0
            chars[track] = current_char
            if count != 1:
                i = track + 1
                temp = str(count)
                while(k < len(temp)):
                    chars[i] = temp[k]
                    i+=1
                    k+=1
            # print(chars)
            track += k + 1
                                            return track