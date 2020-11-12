ans = 0
def dfs(gu, sum):
  global ans
  if len(gu) == 2:
    if ans < sum:
      ans = sum
    return
  for x in range(1, len(gu)-1):
    num = gu[x]
    sum += gu[x-1]*gu[x+1]
    del gu[x]
    dfs(gu, sum)
    sum -= gu[x-1]*gu[x+1]
    gu.insert(x, num)

N = input()
lis = list(map(int, input().split()))
dfs(lis, 0)
print(ans)