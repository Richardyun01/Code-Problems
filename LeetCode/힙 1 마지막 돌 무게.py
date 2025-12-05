class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        while len(stones) > 1:
            stones.sort()
            tmp1 = stones[-1]
            tmp2 = stones[-2]
            stones.pop()
            stones.pop()
            diff = abs(tmp1 - tmp2)
            if diff != 0:
                stones.append(diff)
        if not stones:
            return 0
        return stones[0]