a = int(input())
b = int(input())
c = int(input())

result = [0] * 10

multiple = a * b * c

for i in list(str(multiple)):
    result[int(i)] += 1

for i in result:
    print(i)
