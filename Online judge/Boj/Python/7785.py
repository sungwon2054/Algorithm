# sorted(company,reverse=True)
# for x in company:
#     print(x)
# vs
# print('\n'.join(sorted(company,reverse = True)))
# 이건 뭔 차이지..?

# sorted 함수는 원래 리스트를 수정하지않고 sort를 한다
# 따라서 sort가 되지 않았음
import sys
input = sys.stdin.readline
company = set()
for _ in range(int(input())):
    name, record = input().split()
    if record == "enter":
        company.add(name)
    else:
        company.remove(name)

# print('\n'.join(sorted(company,reverse = True)))
company = list(company)
company.sort(reverse=True)
for x in company:
    print(x)