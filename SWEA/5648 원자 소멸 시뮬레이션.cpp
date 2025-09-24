/*
  접근 방법 및 구현
  - 우선 원자의 정보를 저장하는 구조체부터 정의
  - 현재 위치에서 에너지 값을 표기하는 좌표 배열이 필요
  - 원자들이 한 번에 동시 이동/여러 개가 한 시점 및 한 지점에 충돌 가능을 고려해야 함
  - 원자 정보를 입력받고 음수 좌표를 방지하기 위해서 큰 값을 더하고 곱함
  - 원자의 현재 위치 초기화 후 진행할 때마다 위치에 에너지 누적(값을 기록)
  - 현재 위치 에너지가 자신과 다를 시 = 두 원자가 동시에 존재하여 값이 더해질 시 충돌 발생으로 판정
  - 남은 원자만 따로 모아서 다시 저장
  - 모든 원자가 소멸할 때까지 과정 반복(충돌 못 하는 원자는 지도를 벗어나면 소멸)
*/

#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
struct Atom {
    int x;
    int y;
    int dir;
    int K;
};
int N;
int map[4001][4001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<Atom> A;
int move_atoms() {
    int res = 0;
    while (!A.empty()) {
        int size = (int)A.size();
        for (int i = 0; i < size; i++) {
            // 현재 위치 초기화
            map[A[i].y][A[i].x] = 0;
            int dir = A[i].dir;
            int nx = A[i].x + dx[dir];
            int ny = A[i].y + dy[dir];
            // 범위를 벗어나는 경우
            if (nx < 0 || nx > 4000 || ny < 0 || ny > 4000) {
                A[i].K = 0;
                continue;
            }
            A[i].x = nx;
            A[i].y = ny;
            // 현재 위치 에너지 누적
            map[ny][nx] += A[i].K;
        }
        for (int i = 0; i < size; i++) {
            if (A[i].K == 0) continue;
            int x = A[i].x;
            int y = A[i].y;
            // 현재 위치의 누적 에너지가 자신과 다를 시: 충돌 발생
            if (map[y][x] != A[i].K) {
// cout << "x: " << A[i].x << " y: " << A[i].y << endl;
                res += map[y][x];
                map[y][x] = 0;
                A[i].K = 0;
            }
// if (res != 0) cout << "res: " << res << endl;
        }
        // 남은 원자만 다시 저장
        vector<Atom> tmp_vector;
        tmp_vector.assign(A.begin(), A.end());
        A.clear();
        for (int i = 0; i < (int)tmp_vector.size(); i++) {
            if (tmp_vector[i].K != 0) {
                A.push_back(tmp_vector[i]);
            }
        }
    }
    return res;
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
		cin >> N;
		for (int i = 0; i < N; i++) {
		    Atom atom;
		    cin >> atom.x >> atom.y >> atom.dir >> atom.K;
		    // 음수 좌표 방지
		    atom.x += 1000;
		    atom.y += 1000;
		    atom.x *= 2;
		    atom.y *= 2;
		    A.push_back(atom);
		}
		int ans = move_atoms();
		cout << '#' << tc << ' ' << ans << endl;
	}
	return 0;
}