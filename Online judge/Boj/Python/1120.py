a, b = input().split()
count, ans = 0, 1e9
for x in range(len(a), len(b)+1):
  count = 0
  new_b = b[x-len(a):x+len(a)]
  for y in range(len(a)):
    if new_b[y] is not a[y]:
      count+=1 
  ans = min(ans, count)
print(ans)