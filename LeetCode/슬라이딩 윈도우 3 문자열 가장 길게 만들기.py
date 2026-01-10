# 모든 알파벳에 대해 한 번씩 시도하여 최댓값을 갱신하기
# 슬라이딩 윈도우: 임의의 두 포인터를 정의하고 각각에 대해 따로 이동
# 결과적으로 모든 알파벳에 대한 경우의 수를 구하게 되고 여기서 최댓값 획득
# 해시맵을 사용하면 훨씬 빠름
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        ans = 0
        n = len(s)
        # 전체 알파벳에 대해서
        for c in range(ord('A'), ord('Z')+1):
            # 각 문자에 대해
            c = chr(c)
            # 두 포인터와 교체 횟수 정의
            i, j, replaced = 0, 0, 0
            while j < n:
                # j 포인터의 문자가 목표 문자와 일치할 경우: j 포인터 우측으로 이동
                if s[j] == c:
                    j += 1
                # 맞지 않지만 교체 가능할 시(아직 k번을 다 사용하지 않음): 교체하고 j 포인터 우측으로 이동
                elif replaced < k:
                    j += 1
                    replaced += 1
                # i 포인터의 문자가 목표 문자와 일치할 경우: i 포인터 우측으로 이동
                elif s[i] == c:
                    i += 1
                # 맞지 않고 교체 불가능할 시: 다시 교체 가능할 때까지 i 포인터 우측으로 이동
                else:
                    i += 1
                    replaced -= 1
                # 최대 윈도우 크기
                ans = max(ans, j-i)
        return ans