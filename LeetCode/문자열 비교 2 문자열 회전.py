class Solution(object):
    def rotateString(self, s, goal):
        n = len(s)
        for i in range(0, n):
            tmp = ""
            for j in range(i, n):
                tmp += s[j]
            for j in range(0, i):
                tmp += s[j]
            if tmp == goal:
                return True
        return False
        