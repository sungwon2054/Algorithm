# 내가 푼 코드
# for _ in range(int(input())):
#     n = int(input())
#     for y in range(n):
#         for x in range(n):
#             if (y != 0 and y != n - 1) and x > 0 and x < n - 1:
#                 print('J', end='')
#             else:
#                 print('#', end='')
#         print()
#     print()

# 다른 사람 코드 확인
for _ in range(int(input())):
    n = int(input())
    if n == 1:
        print('#\n')
        continue
    print("#"*n,end='')
    print(("\n#"+"J"*(n-2)+"#")*(n-2))
    print("#"*n+'\n')