import sys

n = int(input())
arr = []

for i in range(n):
    arr.append(sys.stdin.readline().strip())

set_arr = set(arr)  # 중복 단어 제거
arr = list(set_arr)  # 다시 list로 변환
arr.sort()
arr.sort(key=len)

for i in arr:
    print(i)
