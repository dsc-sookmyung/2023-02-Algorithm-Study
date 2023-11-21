import sys

n = int(sys.stdin.readline().strip())
m = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]


def pooling(x, y, size):
    if size == 2:
        answer = [m[x][y], m[x+1][y], m[x][y+1], m[x+1][y+1]]
        answer.sort(reverse=True)
        return answer[1]

    lt = pooling(x, y, size//2)
    rt = pooling(x, y+size//2, size//2)
    lb = pooling(x+size//2, y, size//2)
    rb = pooling(x+size//2, y+size//2, size//2)
    answer = [lt, rt, lb, rb]
    answer.sort(reverse=True)

    return answer[1]


print(pooling(0, 0, n))
