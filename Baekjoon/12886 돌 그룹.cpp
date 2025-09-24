/*
  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색

  접근 방법 및 구현
  - 초기 조건 검사: 전체 돌의 합이 3의 배수가 아니면 바로 0 출력
  - 상태 표현: 세 그룹의 상태는 A, B, C지만 돌의 총합이 고정되어 있으므로 2개의 값만 저장 가능
    - 일반적인 상태를 (x, y)로 두고 나머지 하나를 sum-x-y로 구함
    - 항상 정렬하여 저장하면 중복 방문을 피할 수 있음
  - BFS 상태 탐색: 작은 쪽 x2, 큰 쪽 감소를 적용하면서 새로운 상태를 큐에 삽입
    - 돌의 개수를 배열에 넣고 정렬한 후 (최소, 중간) 값을 큐에 넣어 BFS 시작
    - 큐에서 상태를 하나씩 꺼내고 세 그룹 중 두 그룹을 선택하여 돌의 개수를 변환
    - 변환 후 새로운 상태를 정렬하여 방문 여부를 체크한 후 아직 방문하지 않은 상태면 큐에 추가
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int sum = A + B + C;
    if (sum % 3 != 0) {
        cout << 0;
        return 0;
    }
    const int MAX = 1501;
    vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
    int stones[3] = {A, B, C};
    sort(stones, stones+3);
    queue<pair<int, int>> q;
    q.push({stones[0], stones[1]});
    visited[stones[0]][stones[1]] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int z = sum-x-y;
        if (x == y && y == z) {
            cout << 1;
            return 0;
        }
        int arr[3] = {x, y, z};
        for (int i = 0; i < 3; i++) {
            for (int j = i+1; j < 3; j++) {
                if (arr[i] == arr[j]) continue;
                int new_A = arr[i]*2;
                int new_B = arr[j] - arr[i];
                int new_C = arr[3-i-j];
                int new_arr[3] = {new_A, new_B, new_C};
                sort(new_arr, new_arr+3);
                if (!visited[new_arr[0]][new_arr[1]]) {
                    visited[new_arr[0]][new_arr[1]] = true;
                    q.push({new_arr[0], new_arr[1]});
                }
            }
        }
    }
    cout << 0;
    return 0;
}