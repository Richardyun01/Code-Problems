/*
  접근 방법 및 구현
  - 한 번 방문한 자석에는 다시 방문할 필요가 없음
  - 방문할 자석의 번호와 방향을 각각 저장
  - 좌측과 우측의 자석을 확인해 돌려야 한다면 재귀 호출
*/

#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
vector<deque<int>> magnet;
vector<bool> visit;
vector<int> nums;
vector<int> dirs;
// 회전해야 할 자석 탐색
void find(int num, int dir) {
    // 한 번 방문한 자석
    visit[num] = 1;
    // 방문할 자석의 번호와 방향
    nums.push_back(num);
    dirs.push_back(dir);
// cout << "num: " << num << endl;
// cout << "dir: " << dir << endl;
    // 좌우의 자석을 확인해 돌려야 하면 find 호출
    if (num-1 >= 0 && !visit[num-1] && magnet[num-1][2] != magnet[num][6]) {
// cout << "turn left" << endl;
        find(num-1, -dir);
    }
    if (num+1 < 4 && !visit[num+1] && magnet[num][2] != magnet[num+1][6]) {
// cout << "turn right" << endl;
        find(num+1, -dir);
    }
}
// 자석 회전
void move() {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        // 시계 방향 회전: 마지막 원소를 맨 앞에 추가하고 삭제
        if (dirs[i] == 1) {
// cout << "move right: " << magnet[nums[i]][7] << endl;
            magnet[nums[i]].push_front(magnet[nums[i]][7]);
            magnet[nums[i]].pop_back();
        // 반시계 방향 회전: 첫 원소를 맨 뒤에 추가하고 삭제
        } else {
// cout << "move left: " << magnet[nums[i]][0] << endl;
            magnet[nums[i]].push_back(magnet[nums[i]][0]);
            magnet[nums[i]].pop_front();
        }
    }
}
int main(int argc, char** argv)
{
	int tc;
	int T, k;
	cin>>T;
	for(tc = 1; tc <= T; ++tc)
	{
		cin >> k;
		magnet.assign(4, deque<int>(8));
		for (int i = 0; i < 4; i++) {
		    for (int j = 0; j < 8; j++) {
		        cin >> magnet[i][j];
		    }
		}
		// 자석 이동
		for (int i = 0; i < k; i++) {
		    int num, dir;
		    cin >> num >> dir;
		    nums.clear();
		    dirs.clear();
		    visit.assign(4, 0);
		    find(num-1, dir);
		    move();
		}
		int ans = 0;
		for (int i = 0; i < 4; i++) {
		    if (magnet[i][0]) ans += (int)pow(2, i);
		}
		cout << '#' << tc << ' ' << ans << endl;
	}
	return 0;
}