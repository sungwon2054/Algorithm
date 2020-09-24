# 내 풀이는 C스럽게 풀어서
# 다른 사람들은 슬라이싱을 이용해서 더하는 방법을 이용했다.
N, M = map(int, input().split())
arr = list()

for _ in range(N):
    number = list(map(int,input().split()))
    arr.append(number)

for _ in range(int(input())):
    # 내 코드
    # sum = 0
    # location = list(map(int, input().split()))
    # for y in range(location[0] - 1, location[2]):
    #     for x in range(location[1] - 1, location[3]):
    #        sum += arr[y][x]
    # print(sum)
    
    # 다른 사람 풀이
    ans = 0
    i,j,x,y = map(int,input().split())
    for k in range(i-1,x):
        ans += sum(arr[k][j-1:y])
    print(ans)