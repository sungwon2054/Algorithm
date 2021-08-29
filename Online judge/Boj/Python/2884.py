a, b = map(int, input().split())
if b - 45 >= 0:
  b -= 45
else:
  b = 60 + b - 45
  a -= 1
  if a < 0:
    a = 23
print(a,b)