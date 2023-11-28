import sys 
input = sys.stdin.readline

def check_row(row, guess_num):
  for i in range(9):
    if (guess_num == sudoku[row][i]):
      return False
  return True

def check_col(col, guess_num):
  for i in range(9):
    if (guess_num == sudoku[i][col]):
      return False
  return True

def check_box(row, col, guess_num):
  curr_row = (row // 3) * 3
  curr_col = (col // 3) * 3
  for x in range(3):
    for y in range(3):
      if (guess_num == sudoku[curr_row+x][curr_col+y]):
        return False
  return True

def dfs(n):
  if (n == len(zero_location)):
    for j in range(9):
      print(''.join(map(str, sudoku[j])))
    exit()
  
  curr_row, curr_col = zero_location[n]
  for i in range(1, 10):
    if (check_row(curr_row, i) and check_col(curr_col, i) and check_box(curr_row, curr_col, i)):
      sudoku[curr_row][curr_col] = i
      dfs(n+1)
      sudoku[curr_row][curr_col] = 0

sudoku = []
zero_location = []
for i in range(9):
  temp = list(map(int, input().rstrip()))
  for j in range(len(temp)):
    if (temp[j] == 0):
      zero_location.append((i, j)) #0의 위치 튜플로 저장
  sudoku.append(temp)

dfs(0)