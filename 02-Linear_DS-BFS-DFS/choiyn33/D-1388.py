from collections import deque
import sys

n, m = map(int, input().split())

room = [list(map(str, sys.stdin.readline().strip())) for _ in range(n)]

row_cnt = 0
col_cnt = 0


def bfs_row(x, y):
    room[x][y] = 0

    queue = deque()
    queue.append((x, y))

    # 좌, 우만 확인
    dy = [1, -1]

    while queue:
        x, y = queue.popleft()

        for i in range(2):
            ny = dy[i] + y
            if 0 <= ny < m and room[x][ny] == '-':
                queue.append((x, ny))
                room[x][ny] = 0


def bfs_col(x, y):
    room[x][y] = 0

    queue = deque()
    queue.append((x, y))

    # 상, 하만 확인
    dx = [1, -1]

    while queue:
        x, y = queue.popleft()

        for i in range(2):
            nx = dx[i] + x
            if 0 <= nx < n and room[nx][y] == '|':
                queue.append((nx, y))
                room[nx][y] = 0


for i in range(n):
    for j in range(m):
        if room[i][j] == '-':
            bfs_row(i, j)       # 리턴값이 없어도 됨. 방문 표시가 바뀌니까
            row_cnt += 1


for i in range(n):
    for j in range(m):
        if room[i][j] == '|':
            bfs_col(i, j)
            col_cnt += 1


print(row_cnt+col_cnt)
