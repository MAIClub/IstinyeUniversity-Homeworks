import random
from functools import partial  # For formatting print func
sprint = partial(print, end=' ')

table = [[5, 3, 0, 0, 7, 0, 0, 0, 0],
         [6, 0, 0, 1, 9, 5, 0, 0, 0],
         [0, 9, 8, 0, 0, 0, 0, 6, 0],
         [8, 0, 0, 0, 6, 0, 0, 0, 3],
         [4, 0, 0, 8, 0, 3, 0, 0, 1],
         [7, 0, 0, 0, 2, 0, 0, 0, 6],
         [0, 6, 0, 0, 0, 0, 2, 8, 0],
         [0, 0, 0, 4, 1, 9, 0, 0, 5],
         [0, 0, 0, 0, 8, 0, 0, 7, 9]]

zeroTable = [[0, 0, 0, 0, 0, 0, 0, 0, 0],
             [0, 0, 0, 0, 0, 0, 0, 0, 0],
             [0, 0, 0, 0, 0, 0, 0, 0, 0],
             [0, 0, 0, 0, 0, 0, 0, 0, 0],
             [0, 0, 0, 0, 0, 0, 0, 0, 0],
             [0, 0, 0, 0, 0, 0, 0, 0, 0],
             [0, 0, 0, 0, 0, 0, 0, 0, 0],
             [0, 0, 0, 0, 0, 0, 0, 0, 0],
             [0, 0, 0, 0, 0, 0, 0, 0, 0]]


class Sudoku:
    def __init__(self, table=None):
        """Sudoku for 9x9 array"""
        self.table = table

    def __str__(self):
        ret = ""
        for row in range(1, 10):
            if(row == 1):
                ret += "•-----------------------•\n"
            for column in range(1, 10):
                if(column == 1):
                    ret += "|"
                ret += " "
                ret += str(self.table[row - 1][column - 1])
                if(column % 3 == 0):
                    ret += " |"
                if(column == 9):
                    ret += "\n"
            if(row % 3 == 0 and row != 9):
                ret += "|-----------------------|\n"
            if(row == 9):
                ret += "•-----------------------•\n"
        return ret

    def isPossible(self, y, x, num):
        for i in range(9):
            if self.table[y][i] == num:
                return False
        for i in range(9):
            if self.table[i][x] == num:
                return False

            x0 = (y // 3) * 3
            y0 = (x // 3) * 3
            for i in range(3):
                for j in range(3):
                    if self.table[y0 + i][x0 + j] == num:
                        return False
        return True

    def generateTable(self):
        self.table = [[0, 0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0, 0]]

        for n in range(5):
            for i in range(10):
                rRow = random.randint(1, 8)
                rCol = random.randint(1, 8)
                if (self.isPossible(rRow, rCol, i)):
                    self.table[rRow][rCol] = i

    def solve(self):
        for y in range(9):
            for x in range(9):
                if self.table[y][x] == 0:
                    for n in range(1, 10):
                        if self.isPossible(y, x, n):
                            self.table[y][x] = n
                            self.solve()
                            self.table[y][x] = 0
                    return


sudoku = Sudoku(table)

# sudoku.generateTable()
# print(sudoku)
sudoku.solve()
print(sudoku)
