import sys
from collections import deque

input = sys.stdin.readline
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
coin =[]
board = []

q = deque()
ans = -1

n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]
visited = [[[[False for _ in range(m)] for _ in range(n)] for _ in range(m)] for _ in range(n)]

for i in range(n):
  for j in range(m):
    if board[i][j] == 'o':
      coin.append((i,j))

x, y = coin[0]
x1, y1 = coin[1]
q.append([x, y, x1, y1, 0])
visited[x][y][x1][y1] = True

while len(q):
  x, y, x1, y1, cnt = q.popleft()

  if cnt == 10:
    continue

  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    nx1 = x1 + dx[i]
    ny1 = y1 + dy[i]

    if 0 <= nx < n and 0 <= ny < m and 0 <= nx1 < n and 0 <= ny1 < m:
      if visited[nx][ny][nx1][ny1]: continue
      visited[nx][ny][nx1][ny1] = True
      
      if board[nx][ny] == "#":
        nx, ny = x, y
      
      if board[nx1][ny1] == "#":
        nx1, ny1 = x1, y1
      
      q.append([nx, ny, nx1, ny1, cnt+1])

    elif 0 <= nx < n and 0 <= ny < m:
      if ans == -1:
        ans = cnt+1
      else:
        ans = min(ans, cnt+1)
  
    elif 0 <= nx1 < n and 0 <= ny1 < m:
      if ans == -1:
        ans = cnt+1
      else:
        ans = min(ans, cnt+1)
print(ans)
