# ���� ��� �� ����
# - ���� �������� �������� ���� �������� ��ü�ϴ� ����� LRU�� ����ؾ� ��
# - ĳ�ð� ���� ���� ���� ������ ĳ�ø� �����ϰ� ���ο� �Է��� �޴� FIFO -> ť ���
# - ĳ�� ũ�Ⱑ 0�� �� ���� miss�̹Ƿ� 5*���� ����ŭ �ҿ�
# - �� ���� �� ������ ���� �� 1��, �ƴϸ� 5��

from collections import deque

def solution(cacheSize, cities):
    answer = 0
    cache = deque();
    city_low = []
    # ���ø� �ҹ��ڷ�
    for city in cities:
        city_low.append(city.lower())
    for city in city_low:
        # ĳ�� ũ�� 0�� �� (5*����Ʈ ����)��
        if cacheSize == 0:
            answer += 5*len(city_low)
            break
        # ť ���� ������ ���� �� ����-�߰� ����/1��
        elif city in cache:
            cache.remove(city)
            cache.append(city)
            answer += 1
        else:
            # ť�� �� �� ���� ������ ������ �����ϰ� �߰�
            if len(cache) == cacheSize:
                cache.popleft()
                cache.append(city)
                # ������ �����Ƿ� �߰� 5��
                answer += 5
            # ������ �����Ƿ� �߰� 5��
            else:
                cache.append(city)
                answer += 5
    return answer