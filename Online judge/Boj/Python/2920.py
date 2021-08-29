num = ''.join(list(map(str, input().split())))
if num == '12345678':
  print('ascending')
elif num == '87654321':
  print('descending')
else:
  print('mixed')
