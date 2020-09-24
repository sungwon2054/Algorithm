num = int(input())
for _ in range(num):
    num1 = input()
    num1_reverse = ''.join(reversed(num1))
    sum = int(num1) + int (num1_reverse)
    sum_str = str(sum)
    sum_str_reverse = ''.join(reversed(sum_str))

    if sum == int(sum_str_reverse):
        print("YES")
    else:
        print("NO")