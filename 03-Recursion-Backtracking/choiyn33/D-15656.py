import sys

n, m = map(int, input().split())
arr = list(map(int, sys.stdin.readline().split()))
sub = []


def func():
    # m개 완성 되었으면 종료
    if len(sub) == m:
        print(*sub)
        return

    for k in range(n):
        # 하나 추가하고
        sub.append(arr[k])
        # 나머지 정하기
        func()
        # 현재 원소로 가능한 경우는 윗줄에서 끝남
        # 다음 원소 추가를 위해 pop
        sub.pop()


arr.sort()
func()
