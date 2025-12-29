class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        self.mergeSort(nums)
        return nums

    def mergeSort(self, nums):
        # 리스트 길이가 1이 될 때까지 반복
        if len(nums) > 1:
            # 중간 인덱스를 기준으로 좌측과 우측을 재귀적으로 정렬
            m = len(nums) // 2
            L = nums[:m]
            R = nums[m:]
            self.mergeSort(L)
            self.mergeSort(R)
            # 정렬된 양측 리스트를 하나로 합치기
            i = j = k = 0
            # 두 리스트가 모두 값이 남은 경우: L과 R 중 더 작은 쪽을 nums에 넣고 소모한 쪽의 인덱스 증가
            while i < len(L) and j < len(R):
                if L[i] < R[j]:
                    nums[k] = L[i]
                    i += 1
                else:
                    nums[k] = R[j]
                    j += 1
                k += 1
            # 좌측 리스트에 값이 남은 경우: nums에 복사
            while i < len(L):
                nums[k] = L[i]
                i += 1
                k += 1
            # 우측 리스트에 값이 남은 경우: nums에 복사
            while j < len(R):
                nums[k] = R[j]
                j += 1
                k += 1