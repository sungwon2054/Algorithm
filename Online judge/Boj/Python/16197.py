from queue import Queue
import sys

input = sys.stdin.readline

q = Queue()

ans = -1
coin = []
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

n, m = map(int,input().split())
board = [list(input()) for _ in range(n)]
for x in range(n):
  for y in range(m):
    if board[x][y] == 'o':
      coin.append((x,y))

q.put([coin[0][0], coin[0][1], coin[1][0], coin[1][1], 0])

while not q.empty():
  q1 = q.get()
  x, y, x1, y1, cnt = q1[0], q1[1], q1[2], q1[3], q1[4]

  if cnt == 10:
    continue

  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    nx1 = x1 + dx[i]
    ny1 = y1 + dy[i]

    if 0 <= nx < n and 0 <= ny < m and 0 <= nx1 < n and 0 <= ny1 < m:
      if board[nx][ny] == '#':
        nx, ny = x, y
      
      if board[nx1][ny1] == '#':
        nx1, ny1 = x1, y1
        
      q.put([nx, ny, nx1, ny1, cnt+1])

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