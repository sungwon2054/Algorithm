a = int(input())
dp_arr = [0,1,2] + [0] * 1001
def dp(N):
    for x in range(3, N+1):
        dp_arr[x] = (dp_arr[x-1] + dp_arr[x-2])%10007
dp(a)
print(dp_arr[a])
