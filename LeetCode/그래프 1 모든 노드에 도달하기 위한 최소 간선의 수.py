class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        degree = [0]*n
        for u, v in edges:
            degree[v] += 1
        # print(degree)
        ans = []
        for i in range(n):
            if degree[i] == 0:
                ans.append(i)
        # print(ans)
        return ans