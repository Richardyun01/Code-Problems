class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        n = len(nums)-1
        return self.merge(nums, 0, n)

    # 머지 정렬 이용
    # 전체 nums를 아래와 같이 나누기
    # - (0, m): 좌측
    # - (m+1, n-1): 우측
    # - C: 좌측과 우측 사이의 수(nums[p] > 2 * nums[q]를 만족)
    # nums를 계속 받아서 계산된 값을 덮어씌워야 하므로 참조로 받음
    def merge(self, nums, l, r) -> int:
        # 정렬 완료 시 종료
        if l >= r:
            return 0
        # 중앙점
        m = l + (r-l)//2
        # 좌측과 우측에서의 값을 재귀적으로 계산
        res = self.merge(nums, l, m) + self.merge(nums, m+1, r)
        # 좌측 포인터
        i = l
        # 우측 포인터
        j = m+1
        # 임시 배열 인덱스
        k = 0
        # reverse pair 개수 세는 인덱스
        p = m+1
        # 병합된 정합 병렬
        tmp = [0]*(r-l+1)
        while i <= m:
            # 오른쪽 배열에서 조건을 만족하는 인덱스 세기
            while p <= r and nums[i] > 2*nums[p]:
                p += 1
            res += p - (m+1)
            # 병합된 결과를 앞에서부터 순서대로 채우기
            while j <= r and nums[i] >= nums[j]:
                tmp[k] = nums[j]
                k += 1
                j += 1
            tmp[k] = nums[i]
            k += 1
            i += 1
        # 병합 결과 채우기 마무리
        while j <= r:
            tmp[k] = nums[j]
            k += 1
            j += 1
        # nums에 덮어씌우기
        for i in range(0, len(tmp)):
            nums[i+l] = tmp[i]
        return res