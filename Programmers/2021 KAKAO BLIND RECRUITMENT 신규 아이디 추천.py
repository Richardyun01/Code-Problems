# 접근 방법 및 구현
# - 다양한 종류의 문자열 처리 함수 사용 지식을 요구하는 문제
# - lower()/upper(): 문자열 알파벳 소문자/대문자로 변환
# - isalpha()/isdigit(): 문자가 알파벳/숫자인지 판단
# - replace(): 특정 문자열을 다른 문자열로 변환
# - strip(): 문자열의 맨앞뒤 특정 문자를 제거
# - lstrip()/rstrip(): 문자열의 맨앞/맨뒤 특정 문자를 제거
# - 구현 자체는 차례대로 단순하게 넣기만 하면 됨

def solution(new_id):
    answer = ""
    # 1 소문자 치환
    new_id = new_id.lower();
    # 2 문자 제거
    for ch in new_id:
        if ch.isalpha() or ch.isdigit() or ch in ['-', '_', '.']:
            answer += ch
    # 3 .. 치환
    while '..' in answer:
        answer = answer.replace('..', '.')
    # 4 앞뒤 . 제거
    answer = answer.strip('.')
    # 5 빈 문자열 처리
    if len(answer) == 0:
        answer += 'a'
    # 6 문자열 길이 조절
    tmp1 = ""
    if len(answer) >= 16:
        for i in range(0, 15):
            tmp1 += answer[i]
        answer = tmp1
    answer = answer.rstrip('.')
    # 7 2자 이하 문자열 처리
    if len(answer) == 1:
        answer += answer[0]
        answer += answer[0]
    elif len(answer) == 2:
        answer += answer[1]
    print(answer)
    return answer