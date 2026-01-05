class Solution:
    # 1 = 2*0+1 -> k=0
    # 3 = 2*1+1 -> k=1
    # 5 = 2*2+1 -> k=2
    # 7 = 2*3+1 -> k=3
    # 9 = 2*4+1 -> k=4
    # k가 홀수 [3, 7] -> 아래 두 비트가 11
    # k가 짝수 [1, 5, 9] -> 아래 두 비트가 01
    # 2 = 2*1 -> k=1
    # 4 = 2*2 -> k=2
    # 6 = 2*3 -> k=3
    # 8 = 2*4 -> k=4
    # 10 = 2*5 -> k=5
    # k가 홀수 [2, 6, 10] -> 아래 두 비트가 10
    # k가 짝수 [4, 8] -> 아래 두 비트가 00
    # 전체 순서: [3,7, 1,5,9, 2,6,10, 4,8]
    def partition(self, v, start, end, mask) -> int:
        # 각 단계마다 그룹을 둘로 나누기
        # 비트 마스크 1 정의
        # 특정 수에 비트 마스크 적용해 비트가 1이면 앞으로, 0이면 뒤로 보내는 파티션 수행
        j = start
        for i in range(start, end + 1):
            if (v[i] & mask) != 0:
                v[i], v[j] = v[j], v[i]
                j += 1
        # 경계 인덱스 return
        return j

    def sort(self, v, start, end, mask) -> None:
        # 재귀분할
        # 파티션으로 마스크 비트를 기준으로 구간을 둘로 나눔
        # 좌측과 우측에 대해 재귀적으로 처리
        if start >= end:
            return
        mid = self.partition(v, start, end, mask)
        self.sort(v, start, mid - 1, mask << 1)
        self.sort(v, mid, end, mask << 1)

    def beautifulArray(self, n: int) -> List[int]:
        ans = [i + 1 for i in range(n)]
        self.sort(ans, 0, n - 1, 1)
        return ans
        