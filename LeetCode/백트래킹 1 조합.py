class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        def backtrack(remain, c, next):
            # 종료 조건: 더 이상 뽑을 숫자가 없으면
            # 현재 조합 c를 복사해서 결과 리스트에 추가
            if remain == 0:
                # print(c)
                ans.append(c.copy())
            else:
                # 백트래킹
                # next부터 n까지 인덱스를 현재 조합에 추가
                # 뽑아야 할 숫자를 줄이고 재귀 호출
                # 재귀가 끝나면 마지막 숫자 제거(백트래킹)
                for i in range(next, n+1):
                    # print(c)
                    c.append(i)
                    # print(i)
                    backtrack(remain-1, c, i+1)
                    c.pop()
        # (앞으로 더) 뽑아야 할 숫자의 개수
        # 현재까지 선택한 숫자의 리스트
        # 다음에 선택할 수 있는 최소 숫자가 주어짐
        backtrack(k, [], 1)
        return ans