# 접근 방법 및 구현
# - 3진법 예시: 45/3 = 15 ... 0, 15/3 = 5 ... 0, 5/3 = 1 ... 2, 1/3 = 0 ... 1 -> 1200
# - 문자열 뒤집는 방법: 빈 문자열 정의하고 대상 문자열 for문에서 인덱스만큼 더하면 밀려남

import math

def solution(n):
    answer = 0
    tmp = ''
    while n > 0:
        tmp += str(n % 3)
        n = n // 3
    # print(n)
    # print(tmp)
    reverse = ''
    for i in tmp:
        reverse = i + reverse
    # print(reverse)
    for i in range(len(reverse)):
        num = int(reverse[i])
        answer += num*pow(3, i)
    return answer