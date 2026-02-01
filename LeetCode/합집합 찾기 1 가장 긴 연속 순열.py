class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        # dictionary: each key represents number from input array
        # corresponding value indectes length of consecutive sequence
        table = {}
        maxVal = 0
        for num in nums:
            x = table.get(num-1, 0)
            y = table.get(num+1, 0)
            val = x+y+1
            table[num - x] = val
            table[num + y] = val
            maxVal = max(maxVal, val)
        return maxVal