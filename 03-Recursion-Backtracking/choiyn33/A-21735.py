import sys

n, m = map(int, input().split())
yard = list(map(int, sys.stdin.readline().split()))
yard.insert(0, 0)
size = 1


def snowball(t, i, value):
    global size
    value += yard[i]

    if t == 0:      # 종료할 때가 되면, 최종 결과를 비교한다.
        # 어딘가에서 실행된 snowball함수가 더 큰 value값을 가지면 전역변수 size는 대체된다. -> 결국 모든 경우를 계산하고, 비교하는 셈이다.
        size = max(size, value)
        return

    if i == n:      # 시간이 다 되지 않아도, 위치가 끝나면 종료
        size = max(size, value)
        return

    if i+1 <= n:
        snowball(t-1, i+1, value)
    if i+2 <= n:
        snowball(t-1, i+2, value//2)


snowball(m, 0, 1)

print(size)
