/*
  ���� ��� �� ����
  - ��� ��ǥ(�ִ� ����)�� ���� Ž���� �ʿ�
  - NxN ������ Ž���� �� �� N+1���� Ž���� �ؾ� ��� ĭ�� Ž���ϴ� ���� ����
  - ���� ���񽺷� ��� ������ ��� �̻��̸� �ش� ������ �� ������ ��
*/

#include<iostream>
#include<cstring>
#include<queue>
#define endl '\n'
#define MAX 20
using namespace std;
int n, m, ans;
int MAP[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int compare(int a, int b) {
    if (a > b) return a;
    return b;
}
// ���� ���� ���
int benefit(int k) {
    return k*k + (k-1)*(k-1);
}
void bfs(int a, int b) {
    // ���� ���� ���� �� �� ����
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visit[a][b] = true;
    // �������� ���� ��
    if (MAP[a][b] == 1) cnt++;
    // ���� ����
    int service = 1;
// cout << "cnt: " << cnt << endl;
    while (q.empty() == 0) {
        // ���� ������ ���� ũ�� �ʰ� ��
        if (service > n+1) break;
        // ���� ���񽺷� ��� ������ ��� �̻��� ��
        if (cnt*m - benefit(service) >= 0) ans = compare(ans, cnt);
        // ���� �Ÿ��� �ִ� ��� ��
        int s = q.size();
        for (int q_s = 0; q_s < s; q_s++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
// cout << "nx, ny: " << nx << ' ' << ny << endl;
                    if (visit[nx][ny] == false) {
                        visit[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                        // ���� �� ���� ����
                        if (MAP[nx][ny] == 1) cnt++;
                    }
                }
            }
        }
        // ���� ���� ����
        service++;
// cout << "service: " << service << endl;
    }
// cout << "ans: " << ans << endl;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int T;
	cin>>T;
	for(int tc = 1; tc <= T; ++tc)
	{
		ans = 0;
		memset(MAP, 0, sizeof(MAP));
		memset(visit, false, sizeof(visit));
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        cin >> MAP[i][j];
		    }
		}
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        memset(visit, false, sizeof(visit));
		        bfs(i, j);
		    }
		}
		cout << '#' << tc << ' ' << ans << endl;
	}
	return 0;
}