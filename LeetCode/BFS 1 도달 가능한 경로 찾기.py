'''
1. 시작 노드 source를 큐에 넣음
2. 큐에서 하나 꺼냄
3. 그 노드가 destination인지 확인
4. 아니라면 그 노드의 이웃 중 아직 안 간 곳을 큐에 넣음
5. 큐가 빌 때까지 반복
'''
class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        # 딕셔너리를 생성해서 노드끼리 잇기: 인접 리스트 형태로 바꾸기
        '''
        edges = [[0,1], [1,2], [2,3]]
        ->
        0: [1]
        1: [0, 2]
        2: [1, 3]
        3: [2]
        '''
        neighbors = defaultdict(list)
        for n1, n2 in edges:
            neighbors[n1].append(n2)
            neighbors[n2].append(n1)

        # 앞으로 방문할 노드들을 담는 큐
        q = deque([source])
        # 이미 방문한 노드를 기록하는 집합: 시작 노드들을 방문했다고 설정
        seen = set([source])
        # 큐가 빌 때까지
        while q:
            # 앞으로 방문할 다음 노드를 가져옴
            node = q.popleft()
            # 그 노드가 목표일 경우 도달 가능
            if node == destination:
                return True
            # 현재 노드의 이웃들을 확장
            for n in neighbors[node]:
                # 해당 노드가 지금까지 방문하지 않았다면
                if n not in seen:
                    # 방문했다고 처리
                    seen.add(n)
                    # 큐 안에 넣음
                    q.append(n)
        # 일치하는 노드가 없을 경우 도달하지 못함
        return False