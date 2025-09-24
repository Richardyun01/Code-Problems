/*
  접근 방법 및 구현
  - 이동한 개체와 이동해야 하는 개체가 겹치는 처리를 하기 위해 임시적으로 2차원 배열을 만들어 이동에 사용
  - 이동 결과를 임시 배열에 저장하고 여러 개체가 들어 있는 좌표를 처리 후 원래의 map에 옮김
  - 군집을 탐색하여 방향에 따라 이동
  - 테두리에 도달 시 방향 반대로 전환, 수 절반으로 감소
  - 특정 위치에 군집이 2개인 경우 내림차순 정렬, 병합 후 가장 큰 군집의 방향을 유지
  - 하나만 있을 경우 그대로 이동
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
		            // 이동
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
		                // 초기화
		                map[i][j].clear();
		            }
		        }
		    }
		    // tmp에 존재하는 대상 병합 및 방향 설정
		    for (int i = 0; i < n; i++) {
    		    for (int j = 0; j < n; j++) {
    		        if (tmp[i][j].size() >= 2) {
    		            sort(tmp[i][j].begin(), tmp[i][j].end(), cmp);
    		            int sum = 0;
    		            for (int l = 0; l < tmp[i][j].size(); l++) {
    		                sum += tmp[i][j][l].num;
    		            }
    		            // 가장 많이 가진 대상의 방향
    		            Info merged = {sum, tmp[i][j][0].dir};
// cout << "merged: " << sum << ' ' << tmp[i][j][0].dir << endl;
    		            map[i][j].push_back(merged);
    		            // 초기화
    		            tmp[i][j].clear();
    		        } else if (tmp[i][j].size() == 1) {
    		            map[i][j].push_back(tmp[i][j][0]);
// cout << "non-merged: " << tmp[i][j][0].dir << endl;
    		            // 초기화
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