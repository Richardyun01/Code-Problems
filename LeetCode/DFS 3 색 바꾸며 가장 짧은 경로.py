class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        # 각 edge를 색에 따라서 구성
        graph = [defaultdict(list), defaultdict(list)]
        for src, dest in redEdges:
            graph[0][src].append(dest)
        for src, dest in blueEdges:
            graph[1][src].append(dest)

        # 초기화: 모든 거리, 방문 여부, bfs 가능성(노드 0부터 시작)
        min_dist = [-1] * n
        vis = set()
        q = deque([(0, 0), (0, 1)])
        dist = 0

        while q:
            for _ in range(len(q)):
                # 현재 노드 가져오기
                cur_node, last_col = q.popleft()
                # 현재 노드의 최소 거리가 정해지지 않았으면 현재 거리로 설정
                if min_dist[cur_node] == -1:
                    min_dist[cur_node] = dist
                # 방문한 것으로 처리
                vis.add((cur_node, last_col))
                # 색 반전
                next_col = last_col ^ 1
                # 그래프 내 인접한 edge에 대해서 방문하지 않았으면 탐색 대상에 추가
                for neigh in graph[next_col][cur_node]:
                    if (neigh, next_col) not in vis:
                        q.append((neigh, next_col))
            # 다음 거리 레벨로 이동
            dist += 1
        return min_dist