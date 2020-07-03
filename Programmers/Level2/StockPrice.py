def solution(prices):
    answer = []
    for x in range(len(prices)):
        cnt = 0
        flag = False
        for y in range(x+1, len(prices)):
            if prices[x] <= prices[y]:
                cnt += 1   
            else:
                cnt += 1
                flag = True
            if flag == True:
                break
        answer.append(cnt)
    return answer