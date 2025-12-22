class Solution(object):
    def maxRepeating(self, sequence, word):
        ans = 0
        cur = 1
        # 단어가 문자열 내에 존재하는 경우
        while len(word) * cur <= len(sequence):
            repeat = word * cur
            if repeat in sequence:
                ans = cur
                cur += 1
            else:
                # 더 이상 못 찾을 경우 중지
                break
        return ans