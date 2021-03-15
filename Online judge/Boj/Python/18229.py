n, m, k = map(int, input().split())
order = [ list(map(int, input().split())) for _ in range(n) ]
sum = [0] * n
count = 0
ans = 0
flag = False
for x in range(m):
  for y in range(n):
    sum[y] += order[y][x]
    if sum[y] >= k:
      ans = y + 1
      count = m * count + x + 1
      flag = True
      break
  if flag:
      break
  if x == m - 1:
    x = -1
    count += 1
print(ans, count)
