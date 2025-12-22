class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        n = len(nums)
        even = [0]*(n+1)
        odd = [0]*(n+1)
        for i in range(n-1, -1, -1):
            if i % 2 == 0:
                even[i] += nums[i]
            else:
                odd[i] += nums[i]
            even[i] += even[i+1]
            odd[i] += odd[i+1]
        even_sum = 0
        odd_sum = 0
        ans = 0
        for i in range(0, n):
            if even_sum+odd[i+1] == odd_sum+even[i+1]:
                ans += 1
            if i % 2 == 0:
                even_sum += nums[i]
            else:
                odd_sum += nums[i]
        return ans