/*
  접근 방법 및 구현
  - 모든 좌표(최대 영역)에 대한 탐색이 필요
  - NxN 영역의 탐색을 할 시 N+1까지 탐색을 해야 모든 칸을 탐색하는 것이 가능
  - 현재 서비스로 얻는 이익이 비용 이상이면 해당 서비스의 집 개수가 답
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
// 서비스 제공 비용
int benefit(int k) {
    return k*k + (k-1)*(k-1);
}
void bfs(int a, int b) {
    // 현재 서비스 범위 내 집 개수
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visit[a][b] = true;
    // 시작점이 집일 시
    if (MAP[a][b] == 1) cnt++;
    // 서비스 범위
    int service = 1;
// cout << "cnt: " << cnt << endl;
    while (q.empty() == 0) {
        // 서비스 범위가 도시 크기 초과 시
        if (service > n+1) break;
        // 현재 서비스로 얻는 이익이 비용 이상일 시
        if (cnt*m - benefit(service) >= 0) ans = compare(ans, cnt);
        // 현재 거리에 있는 노드 수
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
                        // 집일 시 개수 증가
                        if (MAP[nx][ny] == 1) cnt++;
                    }
                }
            }
        }
        // 서비스 범위 증가
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