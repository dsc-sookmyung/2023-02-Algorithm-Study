# 입력
n = int(input())
level = list(map(int, input().split())) # 난이도별 풀 문제

exam = []
for _ in range(n):
    exam.append(list(map(int, input().split())))

exam.sort()
res = 0
before_level = 1
before_time = 0
first_clear = True

for i, j in exam:
    if level[i-1] > 0:
        res += j
        level[i-1] -= 1

        # 처음 푼 경우
        if first_clear:
            first_clear = False

        # 난이도가 같은 경우
        elif before_level == i:
            res += (j - before_time)

        # 난이도가 다른 경우
        elif before_level != i:
            res += 60

        before_level = i
        before_time = j
print(res)