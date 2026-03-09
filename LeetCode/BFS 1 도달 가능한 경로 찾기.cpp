class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // unordered_map을 생성해서 노드끼리 잇기: 인접 리스트 형태로 바꾸기
        /*
        edges = [[0,1], [1,2], [2,3]]
        ->
        0: [1]
        1: [0, 2]
        2: [1, 3]
        3: [2]
        */
        unordered_map<int, vector<int>> neighbors;
        for (auto& edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            neighbors[n1].push_back(n2);
            neighbors[n2].push_back(n1);
        }

        // 앞으로 방문할 노드들을 담는 큐
        deque<int> q;
        q.push_back(source);
        // 이미 방문한 노드를 기록하는 집합: 시작 노드들을 방문했다고 설정
        unordered_set<int> seen;
        seen.insert(source);
        // 큐가 빌 때까지
        while (!q.empty()) {
            // 앞으로 방문할 다음 노드를 가져옴
            int node = q.front();
            q.pop_front();
            // 그 노드가 목표일 경우 도달 가능
            if (node == destination) {
                return true;
            }
            // 현재 노드의 이웃들을 확장
            for (auto n : neighbors[node]) {
                // 해당 노드가 지금까지 방문하지 않았다면
                if (seen.find(n) == seen.end()) {
                    // 방문했다고 처리
                    seen.insert(n);
                    // 큐 안에 넣음
                    q.push_back(n);
                }
            }
        }
        // 일치하는 노드가 없을 경우 도달하지 못함
        return false;
    }
};