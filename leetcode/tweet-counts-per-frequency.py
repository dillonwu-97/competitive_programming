from collections import defaultdict
import bisect 
class TweetCounts:
    def __init__(self):
        self.d = defaultdict(list)
    def recordTweet(self, tweetName: str, time: int) -> None:
        self.d[tweetName].append(time)
    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: 
        int, endTime: int) -> List[int]:
        interval = endTime - startTime
        # print(interval)
        if freq == "hour": f = 3600
        elif freq == "minute": f = 60
        elif freq == "day": f = 3600 * 60
        ret = [0] * (interval // f + 1)
        self.d[tweetName].sort()
        s = bisect.bisect_left(self.d[tweetName], startTime)
        e = bisect.bisect_right(self.d[tweetName], endTime+1)
        # print(freq, self.d[tweetName], startTime, endTime)
        # print(s,e )
        for i in range(s, e):
            # print("i is ", self.d[tweetName][i])
            if startTime <= self.d[tweetName][i] <= endTime:
                ret[ (self.d[tweetName][i] - startTime) // f] += 1
        return ret
                        # Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)