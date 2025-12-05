class Solution(object):
    def isPossible(self, target):
        # 모든 값의 전체 합
        s = sum(target)
        #  최대 힙 구성
        pq = [-x for x in target]
        heapify(pq)
        # 모든 원소가 1이 될 때까지
        while -pq[0] > 1:
            # 현재 최대 원소
            mx = -heappop(pq)
            # 다른 원소들의 모든 합
            t = s - mx
            # 합이 0이 되거나 최대가 다른 것의 합일 시 불가
            if t == 0 or mx - t < 1:
                return False
            # 최대에서 다른 합을 계속 빼기
            x = mx % t
            if mx % t == 0:
                x = t
            # 이전 값을 푸시
            heappush(pq, -x)
            # 전체 합을 업데이트
            s = s - mx + x
        # 모두 통과할 시(모든 원소 = 1) 완료
        return True
        