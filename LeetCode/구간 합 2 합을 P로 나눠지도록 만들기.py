class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        need = sum(nums) % p
        hashmap = {0: -1}
        cur = 0
        res = n = len(nums)
        for i, num in enumerate(nums):
            cur = (cur + num) % p
            hashmap[cur] = i
            if (cur - need) % p in hashmap:
                res = min(res, i - hashmap[(cur - need) % p])
        if res < n:
            return res
        else:
            return -1