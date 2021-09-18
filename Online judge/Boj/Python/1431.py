a = []
b = {}
for _ in range(int(input())):
  a.append(input())
for x in a:
  sum = 0
  for y in x:
    if y.isdigit():
      sum += int(y)
  b[x] = sum
b = sorted(b.items(), key=lambda x: (len(x[0]), x[1], x[0]) )
for x in b:
  print(x[0])
