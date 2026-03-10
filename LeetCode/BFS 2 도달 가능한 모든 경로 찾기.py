class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans = []
        # 모든 경로의 시작 노드 정의: 0에서 시작
        q = deque([[0]])
        # 전체 
        while q:
            # 큐에서 가장 앞을 빼서 현재 탐색하고자 하는 경로로 사용
            path = q.popleft()
            # 현재 경로의 맨 뒤가 그래프의 길이-1(초기 0에서 시작을 뺌)과 같을 시 경로가 존재함
            if path[-1] == len(graph)-1:
                ans.append(path)
            # 현재 그래프의 끝 노드에서 그래프의 모든 가능한 경로를 시도
            # 그래프의 각 경로 맨 뒤에 대해서 현재 경로와 이어지는 노드를 큐에 넣음
            else:
                for child in graph[path[-1]]:                
                    q.append(path + [child])
        
        return ans