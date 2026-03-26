class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // 각 정류장을 지나는 버스 저장하는 맵
        unordered_map<int, vector<int>> to_routes;
        // 정류장-노선 저장
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                to_routes[stop].push_back(i);
            }
        }
        // (정류장, 버스 수) 저장
        queue<pair<int, int>> bfs;
        bfs.push({source, 0});
        // 정류장 방문 여부 확인
        unordered_set<int> vis;
        vis.insert(source);
        // 모든 도달 가능 정류장에 대해
        while (!bfs.empty()) {
            // 현재 정류장이 목표면 탄 버스 수 반환
            auto [stop, bus] = bfs.front();
            bfs.pop();
            if (stop == target) {
                return bus;
            }
            // 현재 정류장 지나는 모든 버스 노선에 대해 해당 노선의 정류장을 방문하지 않았으면 버스 한 번 더 탄 것으로 처리
            for (int i : to_routes[stop]) {
                for (int j : routes[i]) {
                    if (vis.find(j) == vis.end()) {
                        bfs.push({j, bus+1});
                        vis.insert(j);
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};