p = [list(map(int, input())) for _ in range(9)]


def find_empty():
    for i in range(9):
        for j in range(9):
            if p[i][j] == 0:
                return i, j
    return None, None           # 다 채워져있을 때


def valid(x, y, val):       # [x][y]에 val숫자를 넣을 수 있는가?
    for i in range(9):
        if p[x][i] == val:  # 해당 행에 이미 val가 사용되었으면,
            return False
        if p[i][y] == val:  # 해당 열에 이미 val가 사용되었으면
            return False

    col = x // 3 * 3  # 현재의 (x, y)가 속한 3x3 사각형의 왼쪽 상단 좌표
    row = y // 3 * 3
    for i in range(3):
        for j in range(3):
            if p[col+i][row+j] == val:
                return False
    return True


def func():
    x, y = find_empty()
    if y is None:
        return True
    else:
        for i in range(1, 10):
            if valid(x, y, i):
                p[x][y] = i
                if func():
                    return True
                p[x][y] = 0
        return False


func()
for i in range(9):
    for j in range(9):
        print(p[i][j], end='')
    print()
