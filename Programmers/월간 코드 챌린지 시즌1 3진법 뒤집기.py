# ���� ��� �� ����
# - 3���� ����: 45/3 = 15 ... 0, 15/3 = 5 ... 0, 5/3 = 1 ... 2, 1/3 = 0 ... 1 -> 1200
# - ���ڿ� ������ ���: �� ���ڿ� �����ϰ� ��� ���ڿ� for������ �ε�����ŭ ���ϸ� �з���

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