# 접근 방법 및 구현
# - 차량 번호와 누적 시간을 카운트할 딕셔너리를 정의
# - 해당 딕셔너리를 통해 입차 및 출차 여부를 처리
# - 출차 차량 = -1: 0으로 처리 시 입차 시간이 00:00인 차량이 출차하지 않는 경우로 인식되는 경우 존재
# - 누적 시간이 기본 시간 이하일 경우 기본 요금만 받음
# - 누적 시간이 기본 시간 초과일 경우 추가 요금을 받음
# - 차 번호 기준으로 오름차순 정렬

import math

def solution(fees, records):
    answer = []
    # 기본 시간, 기본 요금, 분당 요금, 추가 요금
    basic_time, basic_fee, per_min, plus_fee = fees
    # 차량번호와 누적 시간을 카운트
    car = {}
    for idx in records:
        idx = idx.split()
        car[idx[1]] = 0
    
    dic = {}
    for idx in records:
        idx = idx.split()
        tmp = idx[0].split(':')
        in_time = int(tmp[0])*60 + int(tmp[1])
        # 입차
        if idx[2] == 'IN':
            dic[idx[1]] = in_time
        # 출차
        elif idx[2] == 'OUT':
            if idx[1] in dic.keys():
                car[idx[1]] += in_time - dic[idx[1]]
                dic[idx[1]] = -1
    # 입차는 하였지만 출차를 하지 않은 경우
    for key, value in dic.items():
        if value != -1:
            car[key] += 1439 - dic[key]
    for key, value in car.items():
        # 누적 시간이 기본 시간 이하일 경우
        if value <= basic_time:
            answer.append((int(key), basic_fee))
        # 누적 시간이 기본 시간 초과일 경우
        elif value > basic_time:
            tot_fee = basic_fee + math.ceil((value-basic_time)/per_min)*plus_fee
            answer.append((int(key), tot_fee))
    # 차 번호 기준으로 오름차순 정렬
    answer.sort(key=lambda x: x[0])
    real_answer = []
    for key, money in answer:
        real_answer.append(money)
    return real_answer