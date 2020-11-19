import heapq

max_heap = []
min_heap = []
for _ in range(int(input())):
  num = int(input())
  if len(max_heap) == 0 or max_heap[0][1] >= num:
    heapq.heappush(max_heap, (-num, num))
    if len(max_heap) >  len(min_heap) + 1:
      n = heapq.heappop(max_heap)[1]
      heapq.heappush(min_heap, n)

  elif len(min_heap) == 0 or min_heap[0] <= num:
    heapq.heappush(min_heap, num)
    if len(min_heap) > len(max_heap):
      n = heapq.heappop(min_heap)
      heapq.heappush(max_heap, (-n, n))
  
  elif len(max_heap) <= len(min_heap):
    heapq.heappush(max_heap, (-num, num))
  
  else:
    heapq.heappush(min_heap, num)
  
  print(max_heap[0][1])
