import sys 
input = sys.stdin.readline

n = int(input())
words = set([])

for _ in range(n):
  words.add(input().strip())

# 길이가 짧은 것부터 -> list..sort(key=len)
# 길이가 같으면 사전 순으로 -> list.sort()
# 단, 중복된 단어는 하나만 남기고 제거해야 한다. -> set 사용, set을 list로 다시 반환 가능
words_list = list(words)
words_list.sort()
words_list.sort(key=len)

for i in range(len(words_list)):
  print(words_list[i])