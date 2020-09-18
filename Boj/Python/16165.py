N, M = map(int, input().split())
girl_group = {}
girl_group1 = {}
for _ in range(N):
    lis = list()
    group_name = input()
    for _ in range(int(input())):
        name = input()
        girl_group1[name] = group_name
        lis.append(name)
    girl_group[group_name] = lis
for _ in range(M):
    question = input()
    type = int(input())
    if type == 1:
        print(girl_group1[question])
    else:
        print('\n'.join(sorted(girl_group[question])))