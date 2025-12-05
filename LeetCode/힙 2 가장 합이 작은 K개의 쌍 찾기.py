class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        # 가장 합이 작은 쌍이 맨 위에 오는 최소 힙
        min_heap = []
        # 숫자 쌍
        pair = []
        # 힙 튜플에 쌍의 합과 각 인덱스를 저장
        for i in range(min(k, len(nums1))):
            heapq.heappush(min_heap, (nums1[i]+nums2[0], i, 0))
        while min_heap and len(pair) < k:
            # 가장 작은 쌍 가져오기
            pair_sum, i, j = heapq.heappop(min_heap)
            # 리스트에 추가
            pair.append([nums1[i], nums2[j]])
            # nums2[j+1]과의 조합을 체크해 리스트 범위를 벗어나지 않으면 다시 힙으로
            j += 1
            if len(nums2) > j:
                heapq.heappush(min_heap, (nums1[i]+nums2[j], i, j))
        return pair
        