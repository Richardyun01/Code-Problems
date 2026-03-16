class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        # 양방향 연결 그래프 구성
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        # 노드의 방문 여부
        vis = [False] * n
        ans = 0

        # 모든 노드에 대해서
        for i in range(n):
            # 현재 노드가 방문되었다면 패스
            if vis[i] == True:
                continue
            # 현재 노드와 연결된 노드들을 담는 리스트
            bfs = [i]
            # 현재 노드를 방문한 것으로 처리
            vis[i] = True
            # bfs 리스트에 대해서
            for j in bfs:
                # 현재 노드 j와 연결된 모든 이웃에 대해
                for k in adj[j]:
                    # 아직 방문하지 않은 노드면 연결 리스트에 포함시키고 방문 처리
                    if vis[k] == False:
                        bfs.append(k)
                        vis[k] = True
            # 연결 요소의 노드 수가 bfs의 크기일 때 각 노드가 나머지 모든 노드와 연결되어 있으면 완전 그래프
            if all(len(adj[j]) == len(bfs) - 1 for j in bfs):
                ans += 1

        return ans