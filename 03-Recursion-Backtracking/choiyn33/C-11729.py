n = int(input())


def move(a, b, n):  # 원판 n개를 a에서 b기둥으로 옮기는 함수
    if n == 1:
        print(a, b)
    else:
        move(a, 6-a-b, n-1)
        print(a, b)  # move(a,b,1)
        move(6-a-b, b, n-1)


print(pow(2, n)-1)
move(1, 3, n)
