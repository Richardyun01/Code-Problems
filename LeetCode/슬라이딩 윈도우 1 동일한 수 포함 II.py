class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        # 해시맵으로 인덱스와 값을 동시에 저장 
        table = {}
        for i, v in enumerate(nums):
            # print(i, v)
            # 해시맵에 값이 있고 (현재 인덱스 - 해시맵 저장 인덱스 <= k)일 시
            if v in table and i - table[v] <= k:
                print(table)
                return True
            table[v] = i
        # print(table)
        return False