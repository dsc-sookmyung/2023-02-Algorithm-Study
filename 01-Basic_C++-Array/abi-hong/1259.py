import sys 
input = sys.stdin.readline

while (True):
  num = int(input())
  if (num == 0):
    break
  else:
    # 문자열 슬라이싱으로 역순 출력 가능
    reverse_num = list(str(num)[::-1])
    str_num = list(str(num))
    for i in range(len(str_num)):
      if (str_num[i] != reverse_num[i]):
        print('no')
        break
    else:
      print('yes')