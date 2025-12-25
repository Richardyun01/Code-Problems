# 배열 따라가는 방법은 O(n)
# 이진 탐색으로 현재 값보다 다음 값이 더 큰 지점을 찾으변 O(log n)
class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l, r = 0, len(arr)-1
        while l < r:
            m = (int)((l+r)/2)
            if arr[m] < arr[m+1]:
                l = m+1
            else:
                r = m
        return l