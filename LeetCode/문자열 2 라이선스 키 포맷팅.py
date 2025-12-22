class Solution(object):
    def licenseKeyFormatting(self, s, k):
        key = ""
        tmp1 = ""
        tmp2 = ""
        for i in range(0, len(s)):
            if s[i] != '-':
                tmp1 += s[i]
        print("tmp1: " + tmp1)
        ### reversed 사용할 것!
        for i in range(0, len(tmp1)):
            c = upper(tmp1[-i-1])
            if i % k == 0:
                tmp2 += '-'
            tmp2 += c
        print("tmp2: " + tmp2)
        for i in range(0, len(tmp2)-1):
            key += upper(tmp2[-i-1])
        print(key)
        return key

