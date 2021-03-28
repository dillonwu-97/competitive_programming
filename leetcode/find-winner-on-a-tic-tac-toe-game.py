class Solution(object):
    def tictactoe(self, moves):
        """
        :type moves: List[List[int]]
        :rtype: str
        """
        counter = 0
        winner = "Pending"
        flag = False
        space = [[-1,-2,-3],[-4,-5,-6], [-7,-8,-9]]
        for i,j in moves:
            if counter%2==0: 
                space[i][j] = 0
            else: 
                space[i][j] = 1
                        for k in range(3):
                if space[0][k] == space[1][k] == space[2][k] or space[k][0] == 
                    space[k][1] == space[k][2]:
                    flag = True
                    #print(space)
                if space[0][0]==space[1][1]==space[2][2] or space[2][0] == 
                    space[1][1] == space[0][2]:
                    flag = True
                if flag == True:
                    if (counter %2 == 0):
                        winner = "A"
                        break
                    else: 
                        winner = "B"
                        break
            counter+=1
        #8 winning cases
        #print(winner)
        if (counter == 9 and winner == "Pending"): winner = "Draw"
                return winner