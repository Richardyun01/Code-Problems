class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)
        while l < r:
            m = (int)((l+r)/2)
            if nums[m] <= target:
                l = m+1
            else:
                r = m
        if l > 0 and nums[l-1] == target:
            return l-1
        return -1