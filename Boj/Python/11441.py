# list에 숫자를 저장후 각각 연산을 하면 시간초과가 날거같아서
# 각 list에다가 첫번째부터 모두 더한 수를 넣어두고 연산할때는 list(두번째 입력받은수 - (첫번째 입력받은수 - 1))를 출력

# python3로 하니 시간초과라 pypy3로 돌렸더니 통과됐다.

sum = [0] * 100001
N = int(input())
numbers = list(map(int, input().split()))
for x in range(1,N+1):
    if x == 1:
        sum[x] = numbers[x-1]
        continue
    sum[x] = sum[x-1] + numbers[x-1]

for _ in range(int(input())):
    n1, n2 = map(int, input().split())
    print(sum[n2] - sum[n1-1])
    