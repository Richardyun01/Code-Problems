class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # 무작위 피봇값 설정
        pivot = random.choice(nums)
        # 리스트를 3등분: 피봇 여부에 따라
        l = [x for x in nums if x > pivot]
        m = [x for x in nums if x == pivot]
        r = [x for x in nums if x < pivot]

        L, M = len(l), len(m)

        # 각 그룹에 얼마나 많은 원소가 있는지 체크
        # 좌측이 k보다 크거나 같을 시: 좌측에서만 탐색
        if k <= L:
            return self.findKthLargest(l, k)
        # 좌측+중앙이 k보다 작을 시: 우측에서만 탐색
        elif k > L + M:
            return self.findKthLargest(r, k - L - M)
        # 발견
        else:
            return m[0]