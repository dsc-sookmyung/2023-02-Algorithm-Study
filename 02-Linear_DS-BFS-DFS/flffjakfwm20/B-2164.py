from collections import deque

n = int(input())
cards = [i for i in range(1, n+1)]
deque_cards = deque(cards)

while(len(deque_cards) != 1):
  deque_cards.popleft()
  num = deque_cards.popleft()
  deque_cards.append(num)
print(deque_cards[0])