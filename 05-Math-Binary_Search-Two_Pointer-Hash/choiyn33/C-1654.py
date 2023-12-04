import sys

k, n = map(int, input().split())

line = []
for _ in range(k):
    line.append(int(sys.stdin.readline().strip()))


def slove(x):
    cur = 0
    for i in range(k):
        cur += line[i] // x
    return cur >= n     # n개 이상 만들어지는지 아닌지 True-False로 반환


st = 1
en = 2 ** 31-1     # 0x7fffffff

while (st < en):
    mid = (st+en+1)//2  # st+en으로 하면, |st-en|=1 일 때 st가 계속 같을 수도 있음
    if slove(mid) == True:
        st = mid
    else:
        en = mid - 1

print(st)
