class Solution:
    def longestPrefix(self, s: str) -> str:
        # 탐색 포인터 i와 현재까지 일치한 접두사의 길이 j
        # 지금까지 접두사와 접미사가 얼마나 일치했는가
        i, j = 0, -1
        # 실패 배열: s의 길이+1만큼 0으로 초기화하고 첫 원소를 -1로 초기화 
        # 가장 긴 접두사 = 접미사인 경우의 길이
        fail = [0 for _ in range(len(s)+1)]
        fail[0] = -1
        # 인덱스 순회
        while i < len(s):
            # 일치한 접두사가 없거나 
            # 이번에도 접두사와 접미사가 일치할 시
            if j == -1 or s[i] == s[j]:
                # 둘 다 한 칸씩 이동
                i += 1
                j += 1
                # 가장 긴 접두사=접미사의 길이는 j
                fail[i] = j
            # 아니면
            else:
                # 현재 길이 j의 접두사는 실패
                # 그보다 짧은 후보 접두사로 점프
                j = fail[j]
        # 실패 배열 길이의 글자만큼 반환
        return s[:fail[-1]]