n, m = map(int, input().split())
root = []
cnt = 0
chk = [[0] * n for _ in range(n)]
chicken = []
home = []
ans = int(99999999)

def dfs(x, y, cnt, ans):
  if cnt == m:
    min_root = [99999999] * len(home)
    for chicken_index in range(len(chicken)):
      for home_index in range(len(home)):
        min_root[home_index] = min(min_root[home_index], (abs(chicken[chicken_index][0] - home[home_index][0]) + abs(chicken[chicken_index][1] - home[home_index][1])))
    
    sum_cnt = 0
    for a in min_root:
      sum_cnt += int(a)
    ans = min(int(sum_cnt), ans)
    return ans

  for x1 in range(x, n):
    if x1 == x:
      for y1 in range(y, n):
        if chk[x1][y1]: continue
        if root[x1][y1] != 2:
          continue
        chk[x1][y1] = 1
        chicken.append([x1, y1])
        ans = dfs(x1, y1, cnt + 1, ans)
        chk[x1][y1] = 0
        del chicken[-1]
        
    else:
      for y1 in range(n):
        if chk[x1][y1]: continue
        if root[x1][y1] != 2:
          continue
        chk[x1][y1] = 1
        chicken.append([x1, y1])
        ans = dfs(x1, y1, cnt + 1, ans)
        chk[x1][y1] = 0
        del chicken[-1]
  return ans


for x in range(n):
  root.append(list(map(int, input().split())))
  for y in range(n):
    if root[x][y] == 1:
      home.append([x,y])

for x in range(n):
  for y in range(n):
    if root[x][y] != 2:
      continue
    chicken.append([x, y])
    chk[x][y] = 1
    ans = dfs(x, y, cnt + 1, ans)
    chk[x][y] = 0
    del chicken[-1]

print(ans)
