class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.big = [0, big]
        self.medium = [0, medium]
        self.small = [0, small]
    def addCar(self, carType: int) -> bool:
        if carType == 3:
            if self.small[0] != self.small[1]:
                self.small[0]+=1
                return True
            else:
                return False
        elif carType == 2:
            if self.medium[0] != self.medium[1]:
                self.medium[0]+=1
                return True
            else:
                return False
        elif carType == 1:
            if self.big[0] != self.big[1]:
                self.big[0]+=1
                return True
            else:
                return False
                # Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)