from collections import deque

# Variables
N = 0
M = 0
start = None
map_grid = []

dirX = [-1, 1, 0, 0]
dirY = [0, 0, -1, 1]

class Penguin:
    def __init__(self, x=0, y=0, fishCnt=0, time=0):
        self.x = x
        self.y = y
        self.fishCnt = fishCnt
        self.time = time

def solve():
    ans = BFS()
    return str(ans) if ans != -1 else "-1"

def BFS():
    ans = -1
    que = deque()
    que.append(start)

    isVisitedBefore = [[False for _ in range(M)] for _ in range(N)]
    isVisitedAfter = [[False for _ in range(M)] for _ in range(N)]

    isVisitedBefore[start.x][start.y] = True

    while que:
        nowCoor = que.popleft()

        for i in range(4):
            nextX = dirX[i] + nowCoor.x
            nextY = dirY[i] + nowCoor.y

            if nowCoor.fishCnt >= 1:
                if not ableCheck(nextX, nextY, isVisitedAfter):
                    continue
                next = map_grid[nextX][nextY]
                if next == 'F':
                    que.append(Penguin(nextX, nextY, nowCoor.fishCnt + 1, nowCoor.time + 1))
                    isVisitedAfter[nextX][nextY] = True
                elif next == 'H':
                    ans = nowCoor.time + 1
                    return ans
                else:
                    que.append(Penguin(nextX, nextY, nowCoor.fishCnt, nowCoor.time + 1))
                    isVisitedAfter[nextX][nextY] = True
            else:
                if not ableCheck(nextX, nextY, isVisitedBefore):
                    continue
                next = map_grid[nextX][nextY]
                if next == 'F':
                    que.append(Penguin(nextX, nextY, nowCoor.fishCnt + 1, nowCoor.time + 1))
                    isVisitedAfter[nextX][nextY] = True
                elif next == 'H':
                    que.append(Penguin(nextX, nextY, nowCoor.fishCnt, nowCoor.time + 1))
                    isVisitedBefore[nextX][nextY] = True
                else:
                    que.append(Penguin(nextX, nextY, nowCoor.fishCnt, nowCoor.time + 1))
                    isVisitedBefore[nextX][nextY] = True

    return ans

def ableCheck(nextX, nextY, isVisited):
    return 0 <= nextX < N and 0 <= nextY < M and not isVisited[nextX][nextY] and map_grid[nextX][nextY] != 'D'

def input_data():
    global N, M, start, map_grid
    N, M = map(int, input().split())
    map_grid = [list(input().strip()) for _ in range(N)]

    for x in range(N):
        for y in range(M):
            if map_grid[x][y] == 'S':
                start = Penguin(x, y)

# Main
if __name__ == "__main__":
    input_data()
    print(solve())
