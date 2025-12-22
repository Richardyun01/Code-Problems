class Solution(object):
    def eatenApples(self, apples, days):
        n = len(apples)
        ans = 0
        # {상하는 날, 남은 사과 수}를 저장
        minheap = []
        i = 0
        while i < n or minheap:
            # 상한 사과 제거
            while minheap and minheap[0][0] <= i:
                heapq.heappop(minheap)
            # 새로 자란 사과 힙에 추가
            if i < n and apples[i] > 0:
                heapq.heappush(minheap, (i+days[i], apples[i]))
            # 가장 빨리 상하는 사과부터 먹기
            if minheap:
                day, num = heapq.heappop(minheap)
                if num > 1:
                    heapq.heappush(minheap, (day, num-1))
                ans += 1
            i += 1
        return ans
        