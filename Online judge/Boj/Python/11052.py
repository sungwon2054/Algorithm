N = int(input())
p = [0] + list(map(int,input().split()))
d = [0] * (N + 1)
def dp(N):
    for x in range(1, N + 1):
        for y in range(1, x + 1):
            d[x] = max(d[x], p[y] + d[x - y])

dp(N)
print(d[N])