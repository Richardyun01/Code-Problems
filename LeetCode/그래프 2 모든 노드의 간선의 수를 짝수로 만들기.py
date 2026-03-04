class Solution:
    def isPossible(self, n: int, edges: List[List[int]]) -> bool:
        # 그래프를 인접 리스트로 생성
        # 각 정점마다 연결된 이웃을 저장하기 위해 set() 사용
        graph = [set() for i in range(n)]
        # 입력으로 주어진 간선들을 그래프에 추가
        for i, j in edges:
            graph[i-1].add(j-1)
            # 반대도 연결
            graph[j-1].add(i-1)
        
        # 홀수 차수를 가진 정점들 저장 리스트
        odd = []
        # 각 정점의 연결된 간선 수 확인: 홀수면 odd에 추가
        for i in range(n):
            if len(graph[i]) % 2:
                odd.append(i)

        # 두 정점 사이에 간선을 추가할 수 있는지 체크
        def check(a, b):
            # a가 b의 이웃이 아닌 경우 True
            return a not in graph[b]

        # 홀수인 경우가 2개인 경우
        if len(odd) == 2:
            a, b = odd
            # 정점 i에 대해 a-i와 b-i의 간선을 추가 가능하면 둘 다 짝수로 만들 수 있음
            for i in range(n):
                if check(a, i) and check(b, i):
                    return True
            return False

        # 홀수인 경우가 4개인 경우
        if len(odd) == 4:
            a, b, c, d = odd
            # 두 쌍으로 나누는 3가지 경우에 대해 각각 추가 가능한지 확인
            if check(a, b) and check(c, d):
                return True
            elif check(a, c) and check(b, d):
                return True
            elif check(a, d) and check(c, b):
                return True
            else:
                return False
        
        # 홀수인 경우가 0 -> 항상 만족
        return len(odd) == 0