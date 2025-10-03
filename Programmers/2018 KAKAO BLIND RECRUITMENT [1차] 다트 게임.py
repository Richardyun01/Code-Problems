# 접근 방법 및 구현
# - 수식 구현 문제
# - 수를 일일이 계산하기 보다는 리스트 안에 담아서 한번에 합산하는 것이 나음
# - *가 2번 나왔을 경우 2*2 = 4이므로 따로 알고리즘을 만드는 것 보다 두 번 발동하게 함
# - python 배열의 [-1]: 현재 위치

def solution(dartResult):
    answer = 0
    # 더할 점수들을 리스트로 생성
    score = list()
    # 임시 숫자
    num = ''
    for i in dartResult:
        if i == 'S':
            score.append(int(num))
            num = ''
        elif i == 'D':
            score.append(int(num)**2)
            num = ''
        elif i == 'T':
            score.append(int(num)**3)
            num = ''
        elif i == '*':
            # 첫 번재 기회일 시 첫 수만 2배
            if len(score) == 1:
                score[0] *= 2
            # 아니면 현재와 이전 수를 2배
            else:
                score[-1] *= 2
                score[-2] *= 2
        # 현재 수를 -1배
        elif i == '#':
            score[-1] *= -1
        # 임시 숫자 저장
        else:
            num += i
    #     print(score)
    # print(score)
    answer = sum(score)
    return answer