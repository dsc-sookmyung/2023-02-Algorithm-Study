from collections import deque


class Penguin:
    def __init__(self, x, y, fish_cnt, time):
        self.x = x
        self.y = y
        self.fish_cnt = fish_cnt
        self.time = time


def able_check(x, y, is_visited, n, m):
    return 0 <= x < n and 0 <= y < m and not is_visited[x][y]


def find_minimum_time(matrix, start_x, start_y):
    # n, m = len(matrix), len(matrix[0])
    is_visited_before = [[False] * m for _ in range(n)]
    is_visited_after = [[False] * m for _ in range(n)]

    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    que = deque()
    que.append(Penguin(start_x, start_y, 0, 0))
    is_visited_before[start_x][start_y] = True

    while que:
        now_coor = que.popleft()

        for direction in directions:
            next_x, next_y = now_coor.x + \
                direction[0], now_coor.y + direction[1]

            if able_check(next_x, next_y, is_visited_before, n, m):
                next_cell = matrix[next_x][next_y]

                if next_cell == 'F':
                    que.append(
                        Penguin(next_x, next_y, now_coor.fish_cnt + 1, now_coor.time + 1))
                    is_visited_after[next_x][next_y] = True

                elif next_cell == 'H':
                    return now_coor.time + 1

                else:
                    que.append(
                        Penguin(next_x, next_y, now_coor.fish_cnt, now_coor.time + 1))
                    is_visited_before[next_x][next_y] = True

    return -1


n, m = map(int, input().split())
penguin_village = [input() for _ in range(n)]

# 펭귄의 시작 위치 찾기
start_x, start_y = None, None
for i in range(n):
    for j in range(m):
        if penguin_village[i][j] == 'S':
            start_x, start_y = i, j

result = find_minimum_time(penguin_village, start_x, start_y)
print(result)
