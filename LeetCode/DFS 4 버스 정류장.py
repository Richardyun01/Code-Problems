class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        # 각 정류장을 지나는 버스 저장하는 딕셔너리
        to_routes = collections.defaultdict(set)
        # 정류장-노선 저장
        for i, route in enumerate(routes):
            for j in route:
                to_routes[j].add(i)
        # (정류장, 버스 수) 저장
        bfs = [(source, 0)]
        # 정류장 방문 여부 확인
        vis = set([source])
        # 모든 도달 가능 정류장에 대해
        for stop, bus in bfs:
            # 현재 정류장이 목표면 탄 버스 수 반환
            if stop == target:
                return bus
            # 현재 정류장 지나는 모든 버스 노선에 대해 해당 노선의 정류장을 방문하지 않았으면 버스 한 번 더 탄 것으로 처리
            for i in to_routes[stop]:
                for j in routes[i]:
                    if j not in vis:
                        bfs.append((j, bus+1))
                        vis.add(j)
                routes[i] = []
        return -1