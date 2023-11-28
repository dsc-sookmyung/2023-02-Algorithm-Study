import sys 
input = sys.stdin.readline

n = int(input())
first_file = list(input())
result = [''] * len(first_file)
if (n == 1):
  print("".join(first_file))
else:
  # 첫 문자를 기준으로 비교
  for _ in range(n-1):
    file = list(input())
    for i in range(len(first_file)):
      if (file[i] != first_file[i]):
        result[i] = '?'
      else:
        if (result[i] != '?'):
          result[i] = first_file[i]
  print("".join(result))