class Solution(object):
    def numOfBurgers(self, tomatoSlices, cheeseSlices):
        """
        :type tomatoSlices: int
        :type cheeseSlices: int
        :rtype: List[int]
        """
        if (cheeseSlices > tomatoSlices):
            return []
        tomatoSlices = tomatoSlices * .5 - cheeseSlices
        if tomatoSlices.is_integer(): 
            if (tomatoSlices < 0 or cheeseSlices - tomatoSlices < 0): return 
                []
            else: return [int(tomatoSlices), int(cheeseSlices - tomatoSlices)]
        else: return []
        