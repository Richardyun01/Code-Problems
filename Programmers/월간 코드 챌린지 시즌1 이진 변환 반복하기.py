# 접근 방법 및 구현
# - s가 1이 될 때까지 일련의 과정을 반복
# - s를 변환한 중간 과정 x(0을 모두 제거한 s)는 길이만 필요하므로 직접적으로 구할 필요가 없음
# - 대신 c의 길이를 구하기 위해 현재 문자열의 0의 개수를 구해야 함(count 함수)

def solution(s):
    zeros = 0
    transform = 0
    while s != '1':
        zeros_cur = s.count('0')
        zeros += zeros_cur
        # x의 길이
        c = len(s) - zeros_cur
        # 2진법 변환
        s = bin(c)[2:]
        transform += 1
    return [transform, zeros]