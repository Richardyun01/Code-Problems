# 재귀 이용한 풀이법
# 스택을 사용하면 더 쉽고 빠름
class Solution:
    def decodeString(self, s: str) -> str:
        # 대괄호 매칭 딕셔너리
        # 각 '['에 맞는 ']'의 위치를 계산
        close = {}
        st = []
        for i, c in enumerate(s):
            if c == '[':
                st.append(i)
            elif c == ']':
                close[st.pop()] = i
        # dfs(l, r) 함수
        def solve(l, r):
            # 반복 횟수 저장
            num = 0
            # 문자열 단어 조각 저장
            ans = []
            while l <= r:
                c = s[l]
                # s[i]가 숫자면 num에 계속 누적하기
                if c.isdigit():
                    num = num*10 + int(c)
                # s[i]가 앞에서 읽은 숫자 num만큼 괄호 안 문자열을 반복
                # 문자열을 재귀적으로 디코딩
                # 카운트를 새로 시작
                # 닫는 위치로 인덱스 점프
                elif c == '[':
                    ans.append(num*solve(l+1, close[l]-1))
                    num = 0
                    l = close[l]
                # s[i]가 문자면 현재 임시 단어에 더하기
                else:
                    ans.append(c)
                l += 1
            # 생성된 모든 단어들을 하나로 합치기
            return "".join(ans)
        return solve(0, len(s)-1)