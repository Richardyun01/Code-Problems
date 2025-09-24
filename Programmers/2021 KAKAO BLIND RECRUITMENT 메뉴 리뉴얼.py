# 접근 방법 및 구현
# - 각 주문 별 요리 길이에 따른 조합을 모두 구하기
# - 가능한 모든 조합을 탐색하기 위해 combinations 사용
# - 조합들의 개수를 세기 위해 Counter 사용
# - 길이 별 가장 많이 등장한 조합의 갯수를 파악
# - 구해진 조합에서 가장 많이 등장한 조합의 갯수와 같은 조합을 출력
# - 동일한 조합을 다른 조합으로 분류하지 않도록 sorted로 미리 정령해야 함

import itertools
from collections import Counter

def solution(orders, course):
    answer = []
    max_values = []
    menus = []
    for c in course:
        # course 길이별 최대 조합갯수 탐색
        menu = []
        for order in orders:
            # course의 길이만큼 조합 생성
            menu_can = itertools.combinations(sorted(order), c)
            menu += [a for a in list(menu_can)]
        if len(menu) >= 1:
            max_values.append(Counter(menu).most_common(1)[0][1])
            menus.append(menu)
    # 최소 2명이 선택하고 가장 많이 선택받은 음식 조합
    for max_value, menu in zip(max_values, menus):
        for key, values in Counter(menu).items():
            if max_value == values and values >= 2:
                answer.append("".join(key))
    return sorted(answer)