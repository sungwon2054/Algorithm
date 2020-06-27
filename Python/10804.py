lis = []
for x in range(0, 21):
    lis.append(x)
for _ in range(10):
    lis1 = []
    a, b = map(int, input().split())
    lis[a:b+1] = lis[b:a-1:-1]
for x in range(1,21):
    print(lis[x],end=' ')