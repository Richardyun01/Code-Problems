class DSU:
    def __init__(self, N):
        self.p = list(range(N))

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        self.p[xr] = yr

class Solution:
    def primes_set(self, n):
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0:
                return self.primes_set(n // i) | set([i])
        return set([n])
    
    def largestComponentSize(self, nums: List[int]) -> int:
        n = len(nums)
        UF = DSU(n)
        primes = defaultdict(list)
        for i, num in enumerate(nums):
            pr_set = self.primes_set(num)
            for q in pr_set:
                primes[q].append(i)

        for _, indice in primes.items():
            for i in range(len(indice)-1):
                UF.union(indice[i], indice[i+1])

        return max(Counter([UF.find(i) for i in range(n)]).values())