class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        l = 0
        r = (int)(sqrt(c))
        while l <= r:
            m = l*l+r*r
            if m == c:
                return True
            elif m > c:
                r -= 1
            else:
                l += 1
        return False