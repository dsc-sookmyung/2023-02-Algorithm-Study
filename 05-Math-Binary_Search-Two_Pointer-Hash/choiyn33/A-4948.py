import sys

while True:
    n = int(sys.stdin.readline().strip())
    if n == 0:
        break

    cnt = 0

    for i in range(n+1, 2*n+1):
        if i == 1:
            continue
        elif i == 2:
            cnt += 1
            continue
        else:
            for j in range(2, int(i**(1/2))+1):
                if i % j == 0:  # i가 j로 나누어 떨어진다면
                    break       # i는 소수가 아님
            else:           # i가 나눠떨어지는 수가 없다면
                cnt += 1    # i는 소수임

    print(cnt)
