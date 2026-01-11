class Solution:
    def shortestPalindrome(self, s: str) -> str:
        # 가장 긴 부분 팰린드롬 탐색
        # KMP 알고리즘 이용
        def KMPSearch(s):
            # 임시 문자열 생성(중앙 경계선으로 '?' 붙이기)
            tmp = s + "?"
            # 기존 문자열 뒤집기
            s = s[::-1]
            # 임시 문자열과 기존 문자열 합치기 -> 이러면 원본 문자열 - ? - 뒤집힌 문자열 완성
            tmp = tmp + s
            # 전체 문자열 길이
            n = len(tmp)
            # 가장 긴 팰린드롬 길이를 저장할 해시맵 생성
            lps = [0]*n
            # 문자열 순회
            for i in range(1, n):
                # 인덱스까지의 가장 긴 접두사의 길이
                prefix_len = lps[i-1]
                # 인덱스+1의 길이
                while prefix_len > 0 and tmp[prefix_len] != tmp[i]:
                    prefix_len = lps[prefix_len-1]
                # 현재 인덱스의 문자와 접두사 길이에서의 문자와 동일할 시 다음 문자로 
                if tmp[i] == tmp[prefix_len]:
                    prefix_len += 1
                # 팰린드롬 길이 해시맵 값 정의
                lps[i] = prefix_len
            # 가장 긴 팰린드롬을 반환
            return tmp[0:lps[n-1]]
        longest_prefix = KMPSearch(s)
        # print("가장 긴 부분 팰린드롬: " + longest_prefix)
        rest_to_add = s.replace(longest_prefix, '', 1)
        # print("추가해야 할 문자(거꾸로 붙어야 함): " + rest_to_add)
        ans = ''
        ans += rest_to_add[::-1] + s
        return ans