import random 
grid = [ [0] * 3] * 3
gridMap = { 1 : (0,0) , 2: (0,1), 3: (0,2), 4: (1,0), 5: (1,1), 6:(1,2), 7:(2,0), 8:(2,1), 9:(2,2) } 
player1= True

def randomize(grid):
    for i in range(len(grid)): 
        for j in range(len(grid[i])):
            grid[i][j] = random.randint(0,2)

class GUI: 
    
    def handleInput(self): 
        user_choice = input("Dose epilogi")
        while user_choice < 0 and user_choice >= 10:
            print "Edoses lathos arithmo" 
            user_choise = input("Dose epilogi")
        if (self.validate_choice(user_choice)):
            self.select_place(user_choice)
            player1 = not(player1)
        else: 
            print "H thesi xrisimopoihte"
            self.handleInput()
            
    def validate_choice(self, user_choice):
        position = gridMap[int(user_choice)]
        if grid[position[0]][position[1]] == 0: 
            return True
        else: 
            return False
    
    def select_place(self,user_choice): 
        position = gridMap[int(user_choice)]
        grid[position[0]][position[1]] = 1 if (player1)  else 2

    
    def showGrid(self):  
        for i in range(len(grid)): 
            print "\n"
            tmp = []       
            for j in   range(len(grid[i])): 
                tmp.append(self.showCredential(i,j))
            print tmp
               

    def showCredential(self, i , j ): 
         if grid[i][j] == 0 : 
                return ' '
         elif grid[i][j] == 1: 
                return 'X'
         elif grid[i][j] == 2: 
                return 'O' 

    def menu(self): 
        self.showGrid()
        self.handleInput()
        self.showGrid()

gui = GUI()
#randomize(grid)
gui.menu()
