n, m = map(int, input().split())
dic = {}
ans = []
for _ in range(n):
  a = input()
  dic[a] = 1
for _ in range(m):
  a = input()
  try:
    if dic[a] == 1:
      ans.append(a)
  except:
    pass 
print(len(ans))
sorted(ans)
for x in ans:
  print(x)
