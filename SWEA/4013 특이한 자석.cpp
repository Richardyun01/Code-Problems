/*
  ���� ��� �� ����
  - �� �� �湮�� �ڼ����� �ٽ� �湮�� �ʿ䰡 ����
  - �湮�� �ڼ��� ��ȣ�� ������ ���� ����
  - ������ ������ �ڼ��� Ȯ���� ������ �Ѵٸ� ��� ȣ��
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
// ȸ���ؾ� �� �ڼ� Ž��
void find(int num, int dir) {
    // �� �� �湮�� �ڼ�
    visit[num] = 1;
    // �湮�� �ڼ��� ��ȣ�� ����
    nums.push_back(num);
    dirs.push_back(dir);
// cout << "num: " << num << endl;
// cout << "dir: " << dir << endl;
    // �¿��� �ڼ��� Ȯ���� ������ �ϸ� find ȣ��
    if (num-1 >= 0 && !visit[num-1] && magnet[num-1][2] != magnet[num][6]) {
// cout << "turn left" << endl;
        find(num-1, -dir);
    }
    if (num+1 < 4 && !visit[num+1] && magnet[num][2] != magnet[num+1][6]) {
// cout << "turn right" << endl;
        find(num+1, -dir);
    }
}
// �ڼ� ȸ��
void move() {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        // �ð� ���� ȸ��: ������ ���Ҹ� �� �տ� �߰��ϰ� ����
        if (dirs[i] == 1) {
// cout << "move right: " << magnet[nums[i]][7] << endl;
            magnet[nums[i]].push_front(magnet[nums[i]][7]);
            magnet[nums[i]].pop_back();
        // �ݽð� ���� ȸ��: ù ���Ҹ� �� �ڿ� �߰��ϰ� ����
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
		// �ڼ� �̵�
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