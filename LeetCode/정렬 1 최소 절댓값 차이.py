class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        ans = []
        min_val = 1e9
        arr.sort()
        for i in range(len(arr)-1):
            if abs(arr[i] - arr[i+1]) < min_val:
                min_val = abs(arr[i] - arr[i+1])
        for i in range(len(arr)-1):
            tmp = []
            if abs(arr[i] - arr[i+1]) == min_val:
                tmp.append(arr[i])
                tmp.append(arr[i+1])
                ans.append(tmp)
        return ans
