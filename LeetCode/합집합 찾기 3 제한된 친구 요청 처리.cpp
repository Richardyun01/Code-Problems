class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        // union-find를 위한 초기 부모 배열
        // 각 인원은 자기 자신의 부모
        vector<int> parent(n);
        // iota: 순차적인 순번을 부여하여 초기화
        iota(parent.begin(), parent.end(), 0);

        // 경로 압축이 있는 함수 탐색
        // 주어진 노드의 루트 부모를 반환
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                // 경로 압축: 노드가 바로 부모를 볼 수 있도록 함
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // 각 요청이 처리 가능한지 확인하는 결과 벡터
        vector<bool> result;

        // 각 친구 요청 처리
        for (auto& request : requests) {
            int person1 = request[0];
            int person2 = request[1];

            // 두 사람의 부모 루트 탐색
            int root1 = find(person1);
            int root2 = find(person2);

            // 이미 같은 그룹에 있다면 같은 친구 그룹에 이미 속하므로 자동으로 처리
            if (root1 == root2) {
                result.push_back(true);
            // 같은 그룹에 없다면
            } else {
                // 두 그룹을 합치는게 규정 위반인지 체크
                bool canMerge = true;

                for (auto& restriction : restrictions) {
                    // 각 제약 쌍을 가져오기
                    int restRoot1 = find(restriction[0]);
                    int restRoot2 = find(restriction[1]);

                    // 해당 합병이 제약 있는 쌍을 연결하는지 체크
                    // 각 제약 있는 인원이 각각의 그룹에 속할 때 불가 
                    if ((root1 == restRoot1 && root2 == restRoot2) || 
                        (root2 == restRoot1 && root1 == restRoot2)) {
                        canMerge = false;
                        break;
                    }
                }
                result.push_back(canMerge);

                // 합병 가능한 경우 두 그룹을 합치기
                if (canMerge) {
                    // Union 작업
                    parent[root1] = root2;
                }
            }
        }
        return result;
    }
};