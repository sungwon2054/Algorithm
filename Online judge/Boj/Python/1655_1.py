def b_search(num, number):
  left = 0
  right = len(number) -1
  while left <= right:
    mid = (left + right) // 2

    if number[mid] == num:
      return mid
    if number[mid] < num:
      left = mid + 1
    elif number[mid] > num:
      right = mid - 1
    
  return left
    
number = []
for _ in range(int(input())):
  num = int(input())
  index = b_search(num, number)
  number.insert(index, num)

  if len(number) % 2:
    print(number[len(number) // 2])
  else:
    print(number[len(number) // 2 - 1])