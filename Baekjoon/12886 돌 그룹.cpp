/*
  �˰��� �з�: �׷��� �̷�, �׷��� Ž��, �ʺ� �켱 Ž��

  ���� ��� �� ����
  - �ʱ� ���� �˻�: ��ü ���� ���� 3�� ����� �ƴϸ� �ٷ� 0 ���
  - ���� ǥ��: �� �׷��� ���´� A, B, C���� ���� ������ �����Ǿ� �����Ƿ� 2���� ���� ���� ����
    - �Ϲ����� ���¸� (x, y)�� �ΰ� ������ �ϳ��� sum-x-y�� ����
    - �׻� �����Ͽ� �����ϸ� �ߺ� �湮�� ���� �� ����
  - BFS ���� Ž��: ���� �� x2, ū �� ���Ҹ� �����ϸ鼭 ���ο� ���¸� ť�� ����
    - ���� ������ �迭�� �ְ� ������ �� (�ּ�, �߰�) ���� ť�� �־� BFS ����
    - ť���� ���¸� �ϳ��� ������ �� �׷� �� �� �׷��� �����Ͽ� ���� ������ ��ȯ
    - ��ȯ �� ���ο� ���¸� �����Ͽ� �湮 ���θ� üũ�� �� ���� �湮���� ���� ���¸� ť�� �߰�
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