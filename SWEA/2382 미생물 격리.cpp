/*
  ���� ��� �� ����
  - �̵��� ��ü�� �̵��ؾ� �ϴ� ��ü�� ��ġ�� ó���� �ϱ� ���� �ӽ������� 2���� �迭�� ����� �̵��� ���
  - �̵� ����� �ӽ� �迭�� �����ϰ� ���� ��ü�� ��� �ִ� ��ǥ�� ó�� �� ������ map�� �ű�
  - ������ Ž���Ͽ� ���⿡ ���� �̵�
  - �׵θ��� ���� �� ���� �ݴ�� ��ȯ, �� �������� ����
  - Ư�� ��ġ�� ������ 2���� ��� �������� ����, ���� �� ���� ū ������ ������ ����
  - �ϳ��� ���� ��� �״�� �̵�
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};
struct Info {
    int num;
    int dir;
};
vector<Info> map[101][101];
vector<Info> tmp[101][101];
int n, t, k;
bool cmp(Info a, Info b) {
    return a.num > b.num;
}
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int T;
	cin>>T;
	for(int tc = 1; tc <= T; ++tc)
	{
		cin >> n >> t >> k;
		for (int i = 0; i < k; i++) {
		    int r, c, cnt, dir;
		    cin >> r >> c >> cnt >> dir;
		    map[r][c].push_back({cnt, dir});
		}
		for (int l = 0; l < t; l++) {
		    for (int i = 0; i < n; i++) {
		        for (int j = 0; j < n; j++) {
		            // �̵�
		            if (map[i][j].size() != 0) {
		                Info cur = map[i][j][0];
		                int nr = i + dr[cur.dir-1];
		                int nc = j + dc[cur.dir-1];
// cout << "before nr, nc: " << nr << ' ' << nc << endl;
		                if (nr == 0) {
		                    cur.dir = 2;
		                    cur.num /= 2;
		                } else if (nr == n-1) {
		                    cur.dir = 1;
		                    cur.num /= 2;
		                } else if (nc == 0) {
		                    cur.dir = 4;
		                    cur.num /= 2;
		                } else if (nc == n-1) {
		                    cur.dir = 3;
		                    cur.num /= 2;
		                }
// cout << "dir, num: " << cur.dir << ' ' << cur.num << endl;
		                tmp[nr][nc].push_back({cur.num, cur.dir});
		                // �ʱ�ȭ
		                map[i][j].clear();
		            }
		        }
		    }
		    // tmp�� �����ϴ� ��� ���� �� ���� ����
		    for (int i = 0; i < n; i++) {
    		    for (int j = 0; j < n; j++) {
    		        if (tmp[i][j].size() >= 2) {
    		            sort(tmp[i][j].begin(), tmp[i][j].end(), cmp);
    		            int sum = 0;
    		            for (int l = 0; l < tmp[i][j].size(); l++) {
    		                sum += tmp[i][j][l].num;
    		            }
    		            // ���� ���� ���� ����� ����
    		            Info merged = {sum, tmp[i][j][0].dir};
// cout << "merged: " << sum << ' ' << tmp[i][j][0].dir << endl;
    		            map[i][j].push_back(merged);
    		            // �ʱ�ȭ
    		            tmp[i][j].clear();
    		        } else if (tmp[i][j].size() == 1) {
    		            map[i][j].push_back(tmp[i][j][0]);
// cout << "non-merged: " << tmp[i][j][0].dir << endl;
    		            // �ʱ�ȭ
    		            tmp[i][j].clear();
    		        }
    		    }
    		}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        if (map[i][j].size() != 0) {
		            ans += map[i][j][0].num;
		            map[i][j].clear();
		        }
		    }
		}
		cout << '#' << tc << ' ' << ans << endl;
	}
	return 0;
}