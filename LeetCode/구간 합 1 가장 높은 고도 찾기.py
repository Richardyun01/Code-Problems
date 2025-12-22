class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        altitudes = []
        n = 0
        altitudes.append(n)
        for i in gain:
            n += i
            altitudes.append(n)
        altitudes.sort(reverse=True)
        return altitudes[0]