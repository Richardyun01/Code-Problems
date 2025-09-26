# 접근 방법 및 구현
# - 입력 길이가 짧으므로 완전 탐색 가능
# - 입력된 문자열의 길이의 최대 절반 만큼만 탐색하여 압축 방법을 찾으면 됨
# - 압축 글자 수는 1부터 순차적으로 증가하여 각 경우마다 반복
# - 현재 문자열의 상태가 이전 상태와 동일 시 압축 가능, 그렇지 않으면 상태 초기화

def solution(s):
    answer = len(s)
    for i in range(1, len(s)//2+1):
        comp = ''
        # 0부터 i만큼의 문자열 추출
        prev = s[0:i]
        cnt = 1
        # i만큼 크기를 증가시켜 이전 문자열과 비교
        for j in range(i, len(s), i):
            # 이전 상태와 동일 시 압축 횟수 증가
            if prev == s[j:j+i]:
                cnt += 1
            # 다른 문자열(압축 불가)
            else:
                if cnt >= 2:
                    comp += str(cnt) + prev
                else:
                    comp += prev
                # 상태 초기화
                prev = s[j:j+i]
                cnt = 1
        # 남은 문자열 처리
        if cnt >= 2:
            comp += str(cnt) + prev
        else:
            comp += prev
        # 가장 짧은 문자열 길이
        answer = min(answer, len(comp))
    return answer