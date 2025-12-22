class Solution(object):
    def repeatedStringMatch(self, a, b):
        tmp = ""
        cnt = 0
        while (len(tmp) <= 10000):
            tmp += a
            cnt += 1
            # print(tmp)
            if b in tmp:
                # print("found")
                # print(cnt)
                return cnt
        return -1
        
        