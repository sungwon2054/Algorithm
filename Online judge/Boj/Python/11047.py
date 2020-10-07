N, K = map(int, input().split())
lis = [int(input()) for _ in range(N)]
cnt = 0
for x in range(N-1, -1, -1):
    while(K >= lis[x]):
        mok = K // lis[x]
        K %= lis[x]
        cnt += mok
print(cnt)