#include<iostream>
#define endl '\n'
using namespace std;
int arr[8];
bool visited[8];
int N, M;
void DFS(int cnt, int idx) {
    // M���� ��� ����� �� ���� ���� ���
    if (cnt == M) {
        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                cout << arr[i] << ' ';
            }
        }
        cout << endl;
        return;
    }
    // �ĺ� Ž��
    for (int i = idx; i < N; i++) {
        // ���õ� �ε��� �ǳʶٱ�
        if (visited[i]) continue;
        // ���� ���� �� ����
        visited[i] = true;
        DFS(cnt+1, i+1);
        // ��Ʈ��ŷ: ���� ���
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