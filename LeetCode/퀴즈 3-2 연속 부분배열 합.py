class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        table = {0: -1}
        mod = 0
        for i, x in enumerate(nums):
            mod = (mod + x) % k
            if mod not in table:
                table[mod] = i
            elif i - table[mod] > 1:
                return True
        return False