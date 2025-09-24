# 접근 방법 및 구현
# - 시간 체크를 위해 모든 시간을 분으로 변환해 계산
# - 주말일 시 해당 날짜는 스킵
# - 지각일 시 해당 인물은 제외

# 시간을 분으로 변환
def convert(time):
    time = str(time)
    h, m = time[:-2], time[-2:]
    return int(h)*60+int(m)

def solution(schedules, timelogs, startday):
    answer = 0
    # 직원 순회
    for i in range(len(schedules)):
        schedule = convert(schedules[i]) + 10
        timelog = timelogs[i]
        cur_day = startday - 1
        # 출근 기록 순회
        for log in timelog:
            cur_day += 1
            # 주말 제외
            if cur_day % 7 in [0, 6]:
                continue
            # 지각 체크
            if convert(log) > schedule:
                break
        else:
            answer += 1
    return answer