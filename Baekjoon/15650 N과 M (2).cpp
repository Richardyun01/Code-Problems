#include<iostream>
#define endl '\n'
using namespace std;
int arr[8];
bool visited[8];
int N, M;
void DFS(int cnt, int idx) {
    // M개를 모두 골랐을 시 현재 조합 출력
    if (cnt == M) {
        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                cout << arr[i] << ' ';
            }
        }
        cout << endl;
        return;
    }
    // 후보 탐색
    for (int i = idx; i < N; i++) {
        // 선택된 인덱스 건너뛰기
        if (visited[i]) continue;
        // 원소 선택 후 시작
        visited[i] = true;
        DFS(cnt+1, i+1);
        // 백트래킹: 선택 취소
        visited[i] = false;
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        arr[i] = i+1;
        visited[i] = false;
    }
    DFS(0, 0);
    return 0;
}