# 접근 방법 및 구현
# - 스테이지보다 더 큰 숫자가 존재할 시 패스로 간주하고 스킵
# - 정렬 후 원본 인덱스를 구하기 위해 현재 값과 인덱스를 각각 쌍으로 삽입하는 별도의 리스트 생성해야 함
# - 값을 기준으로 정렬해야 하므로 sort의 키에 람다식을 사용해야 함
# - 정렬된 리스트에 인덱스만 복사

def solution(N, stages):
    answer = []
    stage_cnt = []
    stage_check = []
    for i in range(N):
        stage_cnt.append(0)
    for stage in stages:
        if stage > N:
            continue
        else:
            stage_cnt[stage-1] += 1
    total = len(stages)
    for i in range(len(stage_cnt)):
        tmp = total
        # 쌍으로 삽입해야 인덱스 확보 가능, 0으로 나누어지는 경우 방지
        stage_check.append((i, stage_cnt[i] / tmp if tmp > 0 else 0))
        total -= stage_cnt[i]
    # 값 기준 내림차순 정렬
    stage_check.sort(key=lambda x: (-x[1], x[0]))
    # print(stage_check)
    # 정렬된 리스트의 원래 인덱스만
    answer = [i+1 for i, _ in stage_check]
    return answer