class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        // 그래프를 인접 리스트로 저장, 각 정점에 연결된 이웃들을 unordered_set으로 관리
        vector<unordered_set<int>> graph(n);
        // 간선 그래프에 추가
        for (auto& e : edges) {
            graph[e[0]-1].insert(e[1]-1);
            // 반대도 연결
            graph[e[1]-1].insert(e[0]-1);
        }

        // 홀수 차수 정점 저장 리스트
        vector<long> odd;
        // 모든 정점의 연결된 간선 수 확인
        for (int i = 0; i < n; i++) {
            // 정점 i의 연결된 간선 수가 홀수인지 체크
            if (graph[i].size() & 1) {
                odd.push_back(i);
            }
        }
        // 0인 경우: 항상 참
        if (odd.size() == 0) {
            return true;
        }
        // 2인 경우
        if (odd.size() == 2) {
            // 그래프 내 모든 정점에 대해서 두 간선 추가할 수 있는지 검사
            // 간선이 존재하는지 체크하고 둘다 없으면 새 간선 추가
            for (auto& g : graph) {
                if (!g.count(odd[0]) && !g.count(odd[1])) {
                    return true;
                }
            }
        }
        // 4인 경우
        // 4개의 정점을 쌍으로 묶는 3가지 경우 검사
        if (odd.size() == 4) {
            if (!graph[odd[0]].count(odd[1]) && !graph[odd[2]].count(odd[3])) {
                return true;
            }
            if (!graph[odd[0]].count(odd[2]) && !graph[odd[1]].count(odd[3])) {
                return true;
            }
            if (!graph[odd[0]].count(odd[3]) && !graph[odd[1]].count(odd[2])) {
                return true;
            }
        }
        return false;
    }
};