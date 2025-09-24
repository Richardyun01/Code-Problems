# ���� ��� �� ����
# - ���� ��ȣ�� ���� �ð��� ī��Ʈ�� ��ųʸ��� ����
# - �ش� ��ųʸ��� ���� ���� �� ���� ���θ� ó��
# - ���� ���� = -1: 0���� ó�� �� ���� �ð��� 00:00�� ������ �������� �ʴ� ���� �νĵǴ� ��� ����
# - ���� �ð��� �⺻ �ð� ������ ��� �⺻ ��ݸ� ����
# - ���� �ð��� �⺻ �ð� �ʰ��� ��� �߰� ����� ����
# - �� ��ȣ �������� �������� ����

import math

def solution(fees, records):
    answer = []
    # �⺻ �ð�, �⺻ ���, �д� ���, �߰� ���
    basic_time, basic_fee, per_min, plus_fee = fees
    # ������ȣ�� ���� �ð��� ī��Ʈ
    car = {}
    for idx in records:
        idx = idx.split()
        car[idx[1]] = 0
    
    dic = {}
    for idx in records:
        idx = idx.split()
        tmp = idx[0].split(':')
        in_time = int(tmp[0])*60 + int(tmp[1])
        # ����
        if idx[2] == 'IN':
            dic[idx[1]] = in_time
        # ����
        elif idx[2] == 'OUT':
            if idx[1] in dic.keys():
                car[idx[1]] += in_time - dic[idx[1]]
                dic[idx[1]] = -1
    # ������ �Ͽ����� ������ ���� ���� ���
    for key, value in dic.items():
        if value != -1:
            car[key] += 1439 - dic[key]
    for key, value in car.items():
        # ���� �ð��� �⺻ �ð� ������ ���
        if value <= basic_time:
            answer.append((int(key), basic_fee))
        # ���� �ð��� �⺻ �ð� �ʰ��� ���
        elif value > basic_time:
            tot_fee = basic_fee + math.ceil((value-basic_time)/per_min)*plus_fee
            answer.append((int(key), tot_fee))
    # �� ��ȣ �������� �������� ����
    answer.sort(key=lambda x: x[0])
    real_answer = []
    for key, money in answer:
        real_answer.append(money)
    return real_answer