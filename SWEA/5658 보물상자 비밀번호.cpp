/*
  접근 방법 및 구현
  - 생성 가능한 비밀번호 경우의 수를 구해야 함
  - 회전 전/후 생성된 16진수를 10진수로 변환하고 벡터에 같은 수가 있는지 중복체크 후 후보를 추가
  - 뚜껑 회전: 현재 글자를 이전 글자로 교체
  - 뚜껑의 한 면에 적힌 16진수의 글자 수만큼 회전시켜야 함
  - 서로 다른 모든 경우의 수를 발생시키기 위해 한 면에 적힌 글자 수인 N/4만큼 회전을 시켜야 함
  - K번쨰로 큰 수를 찾아내기 위해 비밀번호를 내림차순으로 정렬
*/

#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>
#define endl '\n'
using namespace std;
int N, K;
vector<char> nums;
vector<int> password;
// 생성 가능한 비밀번호 경우의 수
void get_pass() {
    int cnt = N/4;
    string new_pass = " ";
    for (int i = 0; i < nums.size(); i++) {
        int idx = i % cnt;
        new_pass += nums[i];
        // 사각형의 한 면에 적혀있는 16진수의 마지막 글자인 경우
        if (idx == cnt-1) {
            bool check = true;
            int val = stoi(new_pass, nullptr, 16);
// cout << "new password candidate: " << new_pass << " in dec: " << val << endl;
            for (int j = 0; j < password.size(); j++) {
                // 16진수를 10진수로 변환하고 password에 이전에 추가된 적이 있는지 중복 체크
                if (stoi(new_pass, nullptr, 16) == password[j]) {
                    check = false;
                    break;
                }
            }
            // 중복이 없으면 변환한 값을 push하고 초기화
            if (check) {
                password.push_back(val);
// cout << "added new password: " << val << endl;
            }
            new_pass = " ";
        }
    }
}
void rotate_lock() {
    get_pass();
    for (int i = 0; i < N/4; i++) {
        char tmp;
        char before = nums[0];
        // 회전 시 첫 글자를 마지막 글자로 교체
        nums[0] = nums[nums.size()-1];
        // 모든 현재 글자를 이전 글자로 변환
        for (int j = 1; j < nums.size(); j++) {
            tmp = nums[j];
            nums[j] = before;
            before = tmp;
        }
        // 새 비밀번호를 저장
        get_pass();
    }
    sort(password.begin(), password.end(), greater<int>());
// cout << "sorted password: ";
// for (auto p : password) cout << p << ' ';
// cout << endl;
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
	    nums.clear();
	    password.clear();
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
		    char c;
		    cin >> c;
		    nums.push_back(c);
		}
		rotate_lock();
		cout << '#' << tc << ' ' << password[K-1] << endl;
	}
	return 0;
}
?