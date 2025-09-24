/*
  접근 방법 및 구현
  - 중복순열을 사용: 순서에 영향을 받지 않고(순열) 중복 이용이 가능하게끔 해야 하기 때문
  - 사람의 정보와 계단의 정보를 저장하는 구조체를 정의
  - 사람과 선택한 계단 사이의 거리를 계산: 이를 종료조건을 만족할 때까지 반복
  - 종료조건: 모든 사람이 계단을 내려갈 시
  - 현재 시간 동안 계단에 도착하는 사람이 있으면 대기열에 넣음
  - 계단 이용이 가능하면 계단을 사용하도록 만듬
  - 계단에 도착하면 1분을 대기하므로 거리를 구할 시 1을 더하여 저장
*/

#include<iostream>
#include<cmath>
#include<queue>
#define endl "\n"
#define MAX 10
using namespace std;
struct Stair {
    int x;
    int y;
    int len;
    int num;
};
struct Person {
    int x;
    int y;
    int move_time;
    int start_time;
    int end_time;
    bool finish;
};
int n, p_num, ans;
int MAP[MAX][MAX], Select[MAX];
Person person[MAX];
Stair stair[2];
queue<int> waiting[2];

int min_sort(int a, int b) {
    if (a < b) return a;
    return b;
}
// 맨하튼 거리
int dist(int p_idx, int s_idx) {
    int dx = abs(person[p_idx].x - stair[s_idx].x);
    int dy = abs(person[p_idx].y - stair[s_idx].y);
    return (dx+dy)+1;
}
// 계단을 모두 내려간 사람을 체크: 내려간 사람의 finish를 true로 설정
void stop_move(int t) {
    for (int i = 0; i < p_num; i++) {
        if (person[i].end_time == t) {
            person[i].finish = true;
            stair[Select[i]].num--;
        }
    }
}
// 루프 종료조건
bool check() {
    for (int i = 0; i < p_num; i++) {
        if (person[i].finish == false) return false;
    }
    return true;
}
// 현재 시간에 계단에 도착하는 사람을 대기열에 추가
void go_stairs(int t) {
    for (int i = 0; i < p_num; i++) {
        if (person[i].move_time == t) {
            int idx = Select[i];
            waiting[idx].push(i);
// cout << "[Arrive] t=" << t << ", person " << i << " -> stair " << idx << " (waiting size=" << waiting[idx].size() << ")" << endl;
        }
    }
}
// 사람과 계단 사이의 거리를 계산
void distance() {
    for (int i = 0; i < p_num; i++) {
        person[i].move_time = dist(i, Select[i]);
// cout << "Dist: " << person[i].move_time << endl;
    }
    int t = 0;
    while (1) {
        stop_move(t);
        if (check() == true) break;
        go_stairs(t);
        for (int i = 0; i < 2; i++) {
            int stair_len = stair[i].num;
            int wait_len = waiting[i].size();
            if (stair_len < 3 && wait_len > 0) {
                while (waiting[i].empty() == 0) {
                    if (stair[i].num == 3) break;
                    person[waiting[i].front()].start_time = t;
                    person[waiting[i].front()].end_time = t + stair[i].len;
                    stair[i].num++;
                    waiting[i].pop();
                }
            }
// cout << "[Enter] t=" << t << ", person " << waiting[i].front() << " start=" << t << ", end=" << t + stair[i].len << " (stair " << i << " Num=" << stair[i].num+1 << ")" << endl;
        }
        t++;
    }
    ans = min_sort(ans, t);
}
// 모든 사람이 계산 선택을 완료하면 거리 구하기
void dfs(int cnt) {
    if (cnt == p_num) {
        for (int i = 0; i < p_num; i++) {
            person[i].move_time = person[i].start_time = person[i].end_time = -1;
            person[i].finish = false;
        }
        for (int i = 0; i < 2; i++) {
            while (waiting[i].empty() == 0) waiting[i].pop();
            stair[i].num = 0;
        }
        distance();
        return;
    }
    for (int i = 0; i < 2; i++) {
        Select[cnt] = i;
        dfs(cnt+1);
    }
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
		ans = 999999999;
		int p_idx = 0, idx = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        cin >> MAP[i][j];
		        if (MAP[i][j] == 1) {
		            person[p_idx].x = i;
		            person[p_idx].y = j;
		            person[p_idx].move_time = person[p_idx].start_time = person[p_idx].end_time = -1;
		            person[p_idx].finish = false;
		            p_idx++;
		        } else if (MAP[i][j] >= 2) {
		            stair[idx].x = i;
		            stair[idx].y = j;
		            stair[idx].len = MAP[i][j];
		            stair[idx].num = 0;
		            idx++;
		        }
		    }
		}
		p_num = p_idx;
		dfs(0);
		cout << '#' << tc << ' ' << ans << endl;
	}
	return 0;
}