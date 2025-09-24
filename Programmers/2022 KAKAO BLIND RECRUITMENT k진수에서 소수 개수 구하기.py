# 접근 방법 및 구현
# - 주어진 수를 k진법으로 변환
# - 0을 기준으로 수를 분리
# - 문자열을 수로 변환해 해당 수가 소수인지 판별
# - 수가 0, 1, 공백이면 continue로 건너뛰기

def solution(n, k):
    answer = 0
    new_num = ''
    while n:
        new_num += str(n % k)
        n //= k
    new_num = new_num[::-1]
    # 찾는 소수는 10진법 기준
    new_num = new_num.split('0')
    for i in new_num:
        # 수의 길이가 0이면 패스
        if len(i) == 0:
            continue
        # 수의 길이가 2 미만이면 패스
        if int(i) < 2:
            continue
        # 수가 소수인지 판별
        is_prime = True
        for j in range(2, int(int(i)**0.5)+1):
            if int(i) % j == 0:
                is_prime = False
                break
        if is_prime:
            answer += 1
    return answer