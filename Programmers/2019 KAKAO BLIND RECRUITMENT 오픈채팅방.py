# 접근 방법 및 구현
# - 사용자 이름과 상태를 저장하는 딕셔너리를 정의
# - 앞에가 Enter 또는 Change일 경우(사용자가 갱신되는 경우) 딕셔너리에 저장
# - 각각의 이름에 대해 Enter 또는 Leave일 경우 각각에 맞게 출력

def solution(record):
    answer = []
    users = {}
    for rec in record:
        i = rec.split()
        if i[0] in ['Enter', 'Change']:
            users[i[1]] = i[2]
    for rec in record:
        i = rec.split()
        if i[0] == 'Enter':
            answer.append(users[i[1]]+'님이 들어왔습니다.')
        elif i[0] == 'Leave':
            answer.append(users[i[1]]+'님이 나갔습니다.')
    return answer