class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        ans = 0
        left = 0
        # 각 알파벳 수를 저장하는 해시맵
        cnt = {'a': 0, 'b': 0, 'c': 0}
        # print(cnt)
        for right in range(len(s)):
            # 글자 수 세기
            cnt[s[right]] += 1
            # print(cnt)
            # 모든 글자가 최소 하나씩은 존재하는 동안
            while cnt['a'] > 0 and cnt['b'] > 0 and cnt['c'] > 0:
                # abc가 모두 존재하는 문장은 전체 길이에서 '나머지 우측'을 제외한 만큼 존재
                ans += len(s) - right
                # 해당 알파벳 하나 제거
                cnt[s[left]] -= 1
                # 우측으로 땡기기
                left += 1
        return ans