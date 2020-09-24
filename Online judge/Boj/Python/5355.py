# for _ in range(int(input())):
#     a = list(input().split())
#     num = float(a[0])
#     for x in range(1,len(a)):
#         if a[x] == '@':
#             num *= 3
#         elif a[x] == '#':
#             num -= 7
#         else:
#             num += 5
#     print("{0:.2f}".format(num))

for _ in range(int(input())):
    for i in input().split():
        if i == '@':
            j*=3
        elif i == '%':
            j+=5
        elif i =='#':
            j-=7
        else:
            j=float(i)
    print('%.2f'%j)