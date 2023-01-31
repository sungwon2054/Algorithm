def find(a):
  index = len(a)
  if index == 2:
    return 0
  
  ans = 0
  for x in range(1, index - 1):
    energy = a[x - 1] * a[x + 1]
    b = a[:x] + a[x+1:]
    energy += find(b)
    ans = max(ans, energy)
  return ans

n = int(input())
a = list(map(int, input().split()))
print(find(a))