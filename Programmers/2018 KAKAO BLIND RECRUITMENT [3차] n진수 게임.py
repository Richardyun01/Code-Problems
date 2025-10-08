# 접근 방법 및 구현
# - 딕셔너리를 이요해서 10~15를 대문자로 변환
# - 입력된 수를 진법 n으로 나눈 나머지를 구하여 임시 문자열에 저장하고 뒤집어 return
# - 전체 문자열을 변환하고 길이만큼 반복하여 answer에 각 문자열을 저장

# n진수 변환 함수
def convert(num, n):
    # 각 대문자 반환
    nums = {10:'A', 11:'B', 12:'C', 13:'D', 14:'E', 15:'F'}
    tmp = ''
    if num == 0:
       return '0'
    # 문자열 변환
    while num:
        if num % n >= 10:
            tmp += nums[num % n]
        else:
            tmp += str(num % n)
        num //= n
    # 문자열 뒤집기
    return tmp[::-1]

def solution(n, t, m, p):
    answer = ''
    tmp = ''
    # 변환
    for i in range(t*m):
        tmp += convert(i, n)
    i = p-1
    # 문자열 길이가 t가 될 때까지 반복
    while i < len(tmp):
        if len(answer) == t:
            break
        answer += tmp[i]
        i += m
    return answer