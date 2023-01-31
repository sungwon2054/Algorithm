from itertools import *

root = []
home = []
chicken = []
ans = 99999999
home_min = []

n, m = map(int, input().split())
for x in range(n):
  root.append(list(map(int, input().split())))
  for y in range(len(root[-1])):
    if root[-1][y] == 1:
      home.append([x, y])
    if root[-1][y] == 2:
      chicken.append([x, y])

combi = list(combinations(chicken, m))

for x in combi:
  home_min = [9999999] * len(home)
  cnt = 0
  for y in range(len(x)):
    for z in range(len(home)):
      home_min[z] = min(home_min[z], (abs(x[y][0] - home[z][0]) + abs(x[y][1] - home[z][1])))

  for z in home_min:
    cnt += z
  ans = min(cnt, ans)

print(ans)
