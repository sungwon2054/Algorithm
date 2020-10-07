def fiboCount(n):
    zero = [1, 0]
    one = [0, 1]
    if n >= 2:
        for x in range(2, n + 1):
            zero.append(zero[x - 1]+ zero[x - 2])
            one.append(one[x - 1] + one[x - 2])
    print('{0} {1}'.format(zero[n], one[n]))
N = int(input())
for _ in range(N):
    n = int(input())
    fiboCount(n)