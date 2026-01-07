# 이분탐색
# 임의의 배열 start를 정의하고 intervals의 [i번의 start, i]와 같은 형태로 값을 담음
# i번의 start를 기준으로 start 배열 정렬
# intervals 내에서 end 값에 대해 조건을 만족하는 start 탐색
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        # 입력으로 주어지는 intervals 배열들의 start를 담음
        # [i번의 start, i] 형태
        start = []

        # 이분탐색
        def bs(num):
            # 인덱스 정의
            l = 0
            r = len(start) - 1
            res = -1

            # start의 값은 unique함: end와 일치하는 값 탐색 시 인덱스 리턴
            # start가 더 클 경우: r를 m-1로 설정해 작은 값 탐색
            # start가 더 작을 경우: l을 m+1로 설정해 다시 탐색
            while l <= r:
                m = (l + r) // 2
                if start[m][0] == num:
                    return start[m][1]
                elif start[m][0] >= num:
                    r = m - 1
                    res = start[m][1]
                else:
                    l = m + 1
            return res

        # 1개 밖에 없을 시
        # if len(intervals) == 1:
        #     return [-1]
        res = []
        # start 배열에 값 담고 이분탐색 위해 정렬
        for i in range(len(intervals)):
            start.append((intervals[i][0], i))
        start.sort()
        # 이분탐색 진행
        for (_, end) in intervals:
            res.append(bs(end))
        return res