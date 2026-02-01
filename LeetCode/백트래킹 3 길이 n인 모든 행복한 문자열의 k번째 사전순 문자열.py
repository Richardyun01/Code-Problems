class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        ans = ''
        # 문자 집합: 사전순 생성
        alp = ['a', 'b', 'c']
        # 유효 문자열을 하나 만들 때마다 k를 줄이기
        def backtrack(n, k, s):
            nonlocal ans
            # 종료 조건: 길이 n 도달
            # 길이가 n이면 s는 유효한 happy string
            if len(s) == n:
                # 사전순 목록에서 하나 소비
                k -= 1
                # k가 0이 되면 그 문자열이 원하던 k번째
                # ans에 저장하고 종료
                if k == 0:
                    ans = s
                    return 0
                return k
            else:
                # 재귀: 첫 글자 또는 직전 문자와 같지 않을 때
                for c in alp:
                    if s == '' or s[len(s)-1] != c:
                        # 재귀 호출하여 하위에서 문자열 소비 k에 반영
                        k = backtrack(n, k, s+c)
                        # 하위에서 답 찾았을 시 k가 0이므로 탐색 종료
                        if k == 0:
                            return 0
            return k
        backtrack(n, k, '')
        return ans
