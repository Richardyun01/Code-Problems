# 접근 방법 및 구현
# - 모든 알파벳(토큰)을 보유한 초기 사전 letters를 정의
# - 현재 남은 문자열에서 문자열의 가장 긴 접두어가 사전에 있는지(일치하는지) 연순으로 탐색
# - 새로 찾은 가장 긴 접두어의 사전 인덱스를 결과에 추가
# - 해당 접두어에 그 다음 글자 하나를 더한 문자열을 사전에 등록(출력한 단어+다음 글자를 새 토큰으로 추가)

def solution(msg):
    answer = []
    # 체크가 되지 않는 경우를 방지하기 위해 끝에 임의의 글자 추가
    msg += '_'
    # print(msg)
    letters = list('_ABCDEFGHIJKLMNOPQRSTUVWXYZ')
    while len(msg) > 1:
        i = 0
        while msg[:-i] not in letters:
            i += 1
            # print(i)
        answer += [letters.index(msg[:-i])]
        # print(answer)
        letters += [msg[:-i+1]]
        # print(letters)
        # 가장 긴 단어 체크 위해 역순 탐색
        msg = msg[-i:]
        # print(msg)
    return answer