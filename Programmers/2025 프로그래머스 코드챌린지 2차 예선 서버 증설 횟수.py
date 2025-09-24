# 접근 방법 및 구현
# - 각 시간대별 증설된 서버의 수를 기록해놓아야 함
# - 24시간 동안 
#   - 현재 필요한 서버의 수를 확인
#   - 현재 필요한 서버의 수가 증설된 서버의 수보다 크면
#   - 증설해야 하는 횟수를 계산
#   - 이를 항상 증설
#   - 증설된 서버를 k시간 동안 유지되도록 함

def solution(players, m, k):
    # 증설된 서버의 수
    added_server = [0]*24
    answer = 0
    for i in range(24):
        # 필요한 서버의 수
        p = players[i] // m
        # 필요한 서버의 수가 증설된 서버의 수보다 크면
        if p > added_server[i]:
            # 증설 횟수
            tmp = p - added_server[i]
            # 이를 항상 증설하도록 함
            answer += tmp
            # k시간 동안 켜두기
            if i + k < 24:
                for j in range(i, i+k):
                    added_server[j] += tmp
            else:
                for j in range(i, 24):
                    added_server[j] += tmp
    return answer