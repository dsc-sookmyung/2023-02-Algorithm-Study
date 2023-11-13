from collections import deque
import sys

n = int(input())
map = [list(map(str, sys.stdin.readline().strip())) for _ in range(n)]


def bfs(x, y):
    dx = [-1, -1, 0, 0, 1, -1, 1]
    dy = [-1, 1, -1, 1, -1, 0, 1]
    queue = deque()
    queue.append((x, y))    # 도착지
    map[x][y] = "#"         # 방문 표시
    cnt = 0

    while queue:
        x, y = queue.popleft()

        for i in range(7):
            nx = dx[i]+x
            ny = dy[i]+y

            if 0 <= nx < n and 0 <= ny < n and map[nx][ny] != "#":
                queue.append((nx, ny))
                map[nx][ny] = "#"
                cnt += 1

    return cnt


cnt = 0

for i in range(n):
    for j in range(n):
        if map[i][j] == "F":
            cnt = bfs(i, j)
            break

print(cnt)
