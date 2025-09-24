/*
  접근 방법 및 구현
  - 행 확인 시: 우측으로 증가하는 경우와 감소하는 경우를 탐색
  - 열 확인 시: 하단으로 증가하는 경우와 감소하는 경우를 탐색
  - 높이 차가 2 이상인 경우 건설이 불가
  - 이미 경사로를 건설한 곳에 또 건설해서는 안됨
  - 행 확인 완료 후에는 초기화가 필요
*/

#include<iostream>
#include<cmath>
using namespace std;
int n, len, map[21][21];
bool used[21][21];
// 행 체크
bool row_check(int i) {
    for (int j = 0; j < n-1; j++) {
        // cout << "[row_check] i=" << i << " j=" << j 
        //      << " map[i][j]=" << map[i][j] 
        //      << " map[i][j+1]=" << map[i][j+1] 
        //      << " used[i][j]=" << used[i][j] 
        //      << " used[i][j+1]=" << used[i][j+1] 
        //      << endl;
        // 다음 지점에 경사로 존재할 시
        if (used[i][j+1]) continue;
        // 높이 차이 2 이상
        if (abs(map[i][j] - map[i][j+1]) >= 2) return false;
        if (map[i][j] == map[i][j+1]+1) {
            // 경사로가 밖으로 나가는 경우
            if (j+len >= n) return false;
            for (int k = j+1; k <= j+len-1; k++) {
                if (map[i][k] != map[i][k+1]) return false;
            }
            // 이미 경사로가 놓인 경우
            for (int k = j+1; k <= j+len; k++) {
                if (used[i][k]) return false;
            }
            // 경사로 표기
            for (int k = j+1; k <= j+len; k++) {
                used[i][k] = true;
            }
        }
    }
    for (int j = 0; j < n-1; j++) {
        // 다음 지점에 경사로 존재할 시
        if (used[i][j+1]) continue;
        if (map[i][j] == map[i][j+1] - 1) {
            // 경사로가 밖으로 나가는 경우
            if (j+1-len < 0) return false;
            for (int k = j+1-len; k <= j-1; k++) {
                if (map[i][k] != map[i][k+1]) return false;
            }
            // 이미 경사로가 놓인 경우
            for (int k = j+1-len; k <= j; k++) {
                if (used[i][k]) return false;
            }
            // 경사로 표기
            for (int k = j+1-len; k <= j; k++) {
                used[i][k] = true;
            }
        }
    }
    return true;
}
bool col_check(int j) {
    for (int i = 0; i < n-1; i++) {
        // cout << "[col_check] j=" << j << " i=" << i 
        //      << " map[i][j]=" << map[i][j] 
        //      << " map[i+1][j]=" << map[i+1][j] 
        //      << " used[i][j]=" << used[i][j] 
        //      << " used[i+1][j]=" << used[i+1][j] 
        //      << endl;
        // 다음 지점에 경사로 존재할 시
        if (used[i+1][j]) continue;
        // 높이 차이 2 이상
        if (abs(map[i][j] - map[i+1][j]) >= 2) return false;
        if (map[i][j] == map[i+1][j]+1) {
            // 경사로가 밖으로 나가는 경우
            if (i+len >= n) return false;
            for (int k = i+1; k <= i+len-1; k++) {
                if (map[k][j] != map[k+1][j]) return false;
            }
            for (int k = i+1; k <= i+len; k++) {
                if (used[k][j]) return false;
            }
            for (int k = i+1; k <= i+len; k++) {
                used[k][j] = true;
            }
        }
    }
    for (int i = 0; i < n-1; i++) {
        // 다음 지점에 경사로 존재할 시
        if (used[i+1][j]) continue;
        if (map[i][j] == map[i+1][j] - 1) {
            // 경사로가 밖으로 나가는 경우
            if (i+1-len < 0) return false;
            for (int k = i+1-len; k <= i-1; k++) {
                if (map[k][j] != map[k+1][j]) return false;
            }
            for (int k = i+1-len; k <= i; k++) {
                if (used[k][j]) return false;
            }
            for (int k = i+1-len; k <= i; k++) {
                used[k][j] = true;
            }
        }
    }
    return true;
}
int process() {
    // 사용 가능한 길
    int ret = 0;
    // 가로 방향 확인
    for (int i = 0; i < n; i++) {
// cout << "row check " << i << ": " << row_check(i) << endl;
        if (!row_check(i)) continue;
        ret++;
    }
    // 경사로 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            used[i][j] = false;
        }
    }
    // 세로 방향 확인
    for (int j = 0; j < n; j++) {
// cout << "col check " << j << ": " << col_check(j) << endl;
        if (!col_check(j)) continue;
        ret++;
    }
    return ret;
}
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int tc;
	int T;
	cin>>T;
	for(tc = 1; tc <= T; ++tc)
	{
		cin >> n >> len;
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        cin >> map[i][j];
		    }
		}
		int res = process();
		cout << '#' << tc << ' ' << res << endl;
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        map[i][j] = 0;
		    }
		}
		// 경사로 초기화
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        used[i][j] = false;
		    }
		}
	}
	return 0;
}