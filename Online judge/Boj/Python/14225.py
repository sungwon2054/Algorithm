def combination(arr, n):
  result = []

  if n == 0:
    return [[]]

  for i in range(len(arr)):
    elem = arr[i]
    rest_arr = arr[i+1:]

    for C in combination(rest_arr,n-1):
      result.append([elem]+C)

  return result

check = [False] * 2000000

n = int(input())
arr = list(map(int, input().split()))

for i in range(1, n+1):
  for j in combination(arr, i):
    check[sum(j)] = True

for i in range(1, 2000000):
  if check[i] == False:
    print(i)
    break
