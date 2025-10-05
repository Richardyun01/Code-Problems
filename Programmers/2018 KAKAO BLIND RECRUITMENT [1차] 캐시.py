# 접근 방법 및 구현
# - 가장 오랫동안 참조되지 않은 페이지를 교체하는 방법인 LRU를 사용해야 함
# - 캐시가 가득 차면 가장 오래된 캐시를 제거하고 새로운 입력을 받는 FIFO -> 큐 사용
# - 캐시 크기가 0일 시 전부 miss이므로 5*도시 수만큼 소요
# - 각 도시 당 참조값 있을 시 1초, 아니면 5초

from collections import deque

def solution(cacheSize, cities):
    answer = 0
    cache = deque();
    city_low = []
    # 도시명 소문자로
    for city in cities:
        city_low.append(city.lower())
    for city in city_low:
        # 캐시 크기 0일 시 (5*리스트 길이)초
        if cacheSize == 0:
            answer += 5*len(city_low)
            break
        # 큐 내에 참조값 있을 시 제거-추가 갱신/1초
        elif city in cache:
            cache.remove(city)
            cache.append(city)
            answer += 1
        else:
            # 큐가 찰 시 가장 오래된 참조값 제거하고 추가
            if len(cache) == cacheSize:
                cache.popleft()
                cache.append(city)
                # 참조값 없으므로 추가 5초
                answer += 5
            # 참조값 없으므로 추가 5초
            else:
                cache.append(city)
                answer += 5
    return answer