def dfs(check, current):
  for i in range(len(angle)):
    current += angle[i]

    if(current >= 361):
      current %= 360

    if(check[current]):
      return check
    
    check[current] = True
    dfs(check, current)
  
  return check

n, k = map(int, input().split())
angle = list(map(int, input().split()))
find = list(map(int, input().split()))

for i in range(k):
  check = [False for _ in range(361)]
  check[0] = True
  check = dfs(check, 0)
  check[find[i]]
  if(check[find[i]]):
    print("YES")
  else:
    print("NO")