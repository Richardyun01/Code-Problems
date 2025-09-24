# ���� ��� �� ����
# - �� �ֹ� �� �丮 ���̿� ���� ������ ��� ���ϱ�
# - ������ ��� ������ Ž���ϱ� ���� combinations ���
# - ���յ��� ������ ���� ���� Counter ���
# - ���� �� ���� ���� ������ ������ ������ �ľ�
# - ������ ���տ��� ���� ���� ������ ������ ������ ���� ������ ���
# - ������ ������ �ٸ� �������� �з����� �ʵ��� sorted�� �̸� �����ؾ� ��

import itertools
from collections import Counter

def solution(orders, course):
    answer = []
    max_values = []
    menus = []
    for c in course:
        # course ���̺� �ִ� ���հ��� Ž��
        menu = []
        for order in orders:
            # course�� ���̸�ŭ ���� ����
            menu_can = itertools.combinations(sorted(order), c)
            menu += [a for a in list(menu_can)]
        if len(menu) >= 1:
            max_values.append(Counter(menu).most_common(1)[0][1])
            menus.append(menu)
    # �ּ� 2���� �����ϰ� ���� ���� ���ù��� ���� ����
    for max_value, menu in zip(max_values, menus):
        for key, values in Counter(menu).items():
            if max_value == values and values >= 2:
                answer.append("".join(key))
    return sorted(answer)