class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        # 우선 정렬부터 진행해서 투포인터 가능하게 함
        nums.sort()
        # 가장 가까운 값을 정의: 임의 합으로 초기화
        closest = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)-2):
            # 좌측/우측 포인터 정의
            l = i+1
            r = len(nums)-1
            # 두 포인터가 만날 때까지
            while l < r:
                # 세 포인터의 합
                tmp_sum = nums[l] + nums[r] + nums[i]
                # print("tmp_sum: ", tmp_sum)
                # 현재 합과 타겟 값의 차가 기존 타겟과의 차보다 작을 시 가장 가까운 값을 갱신
                if abs(tmp_sum - target) < abs(closest - target):
                    closest = tmp_sum
                # 발견 시 바로 반환
                if tmp_sum == target:
                    # print("found")
                    return tmp_sum
                # 타겟보다 더 작으면 좌측 포인터를 우측으로 땡김
                elif tmp_sum < target:
                    l += 1
                    # print("l: ", l)
                # 타겟보다 더 크면 우측 포인터를 좌측으로 땡김
                elif tmp_sum > target:
                    r -= 1
                    # print("r: ", r)
        # 동일한 값 없었을 시 가장 가까운 값을 반환
        return closest
