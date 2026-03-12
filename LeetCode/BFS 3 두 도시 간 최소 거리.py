class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        # 인접한 이웃 노드와 거리 정보를 저장하는 리스트
        adj = [[] for _ in range(n+1)]
        # 각 정보를 저장
        for src, dst, dist in roads:
            adj[src].append((dst, dist))
            adj[dst].append((src, dist))

        ans = 10**9
        # 방문했음을 저장하는 리스트
        visit = [False]*(n+1)
        # 1에서 시작함을 의미하는 초기화
        q = deque([1])
        # 1번 노드는 이미 방문함
        visit[1] = True

        while q:
            # 현재 노드에 대해서
            node = q.popleft()
            # 각 이웃과 거리에 대해서
            for neigh, dist in adj[node]:
                # 최소값을 현재 최소값과 거리와 비교
                ans = min(ans, dist)
                # 이웃 노드를 방문하지 않았다면 방문한 것으로 처리
                if not visit[neigh]:
                    visit[neigh] = True
                    q.append(neigh)
        
        return ans