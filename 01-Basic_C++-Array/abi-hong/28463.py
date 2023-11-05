import sys 
input = sys.stdin.readline

direction = input().strip()
jumps = []
for _ in range(2):
  jumps.append(list(input().strip()))

if (direction == 'N'):
  if (jumps[0][0] == '.' and jumps[0][1] == 'P' and jumps[1][0] == 'O' and jumps[1][1] == '.'):
    print('T')
    exit()
  elif (jumps[0][0] == 'P' and jumps[0][1] == '.' and jumps[1][0] == '.' and jumps[1][1] == 'O'):
    print('Lz')
  elif (jumps[0][0] == 'P' and jumps[0][1] == '.' and jumps[1][0] == '.' and jumps[1][1] == 'I'):
    print('F')
  else:
    print('?')
    exit()
elif (direction == 'S'):
  if (jumps[0][0] == '.' and jumps[0][1] == 'O' and jumps[1][0] == 'P' and jumps[1][1] == '.'):
    print('T')
    exit()
  elif (jumps[0][0] == 'O' and jumps[0][1] == '.' and jumps[1][0] == '.' and jumps[1][1] == 'P'):
    print('Lz')
  elif (jumps[0][0] == 'I' and jumps[0][1] == '.' and jumps[1][0] == '.' and jumps[1][1] == 'P'):
    print('F')
  else:
    print('?')
    exit()
elif (direction == 'W'):
  if (jumps[0][0] == 'P' and jumps[0][1] == '.' and jumps[1][0] == '.' and jumps[1][1] == 'O'):
    print('T')
    exit()
  elif (jumps[0][0] == '.' and jumps[0][1] == 'O' and jumps[1][0] == 'P' and jumps[1][1] == '.'):
    print('Lz')
  elif (jumps[0][0] == '.' and jumps[0][1] == 'I' and jumps[1][0] == 'P' and jumps[1][1] == '.'):
    print('F')
  else:
    print('?')
    exit()
elif (direction == 'E'):
  if (jumps[0][0] == 'O' and jumps[0][1] == '.' and jumps[1][0] == '.' and jumps[1][1] == 'P'):
    print('T')
    exit()
  elif (jumps[0][0] == '.' and jumps[0][1] == 'P' and jumps[1][0] == 'O' and jumps[1][1] == '.'):
    print('Lz')
  elif (jumps[0][0] == '.' and jumps[0][1] == 'P' and jumps[1][0] == 'I' and jumps[1][1] == '.'):
    print('F')
  else:
    print('?')
    exit()