class Solution(object):
    def repeatedSubstringPattern(self, s):
        # 입력 문자열의 첫/마지막 글자는 반복되는 부분문자열의 첫/마지막 글자
        # 문자열을 2배로 늘린 뒤 맨 앞과 뒤를 제거
        pat = (s+s)[1:-1]
        # 원본 문자열이 새 문자열에 존재한다면 이는 문자열이 반복되고 있음을 의미
        return pat.find(s) != -1
        