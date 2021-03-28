from collections import Counter
class UndergroundSystem:
    def __init__(self):
        self.d = Counter()
        self.users = {}
        self.dc = Counter()
            def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.users[id] = [t, stationName]
            def checkOut(self, id: int, stationName: str, t: int) -> None:
        s = self.users[id][1] + " " + stationName
        self.d[s] += t - self.users[id][0]
        self.dc[s] += 1
    def getAverageTime(self, startStation: str, endStation: str) -> float:
        s = startStation + " " + endStation
        # print("distance ", self.d)
        # print(self.dc)
        return self.d[s] / self.dc[s]
# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)