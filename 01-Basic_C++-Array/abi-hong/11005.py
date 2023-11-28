import string
import sys 
input = sys.stdin.readline

n, b = map(int, input().split())

# string 모듈
# divmod 내장 함수
# if-else문 한줄
def convert_recursive(n, b):
  number = string.digits + string.ascii_uppercase
  q, r = divmod(n, b)
  return (convert_recursive(q, b) + number[r]) if q else number[r]

print(convert_recursive(n, b))