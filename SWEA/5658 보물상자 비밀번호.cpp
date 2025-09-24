/*
  ���� ��� �� ����
  - ���� ������ ��й�ȣ ����� ���� ���ؾ� ��
  - ȸ�� ��/�� ������ 16������ 10������ ��ȯ�ϰ� ���Ϳ� ���� ���� �ִ��� �ߺ�üũ �� �ĺ��� �߰�
  - �Ѳ� ȸ��: ���� ���ڸ� ���� ���ڷ� ��ü
  - �Ѳ��� �� �鿡 ���� 16������ ���� ����ŭ ȸ�����Ѿ� ��
  - ���� �ٸ� ��� ����� ���� �߻���Ű�� ���� �� �鿡 ���� ���� ���� N/4��ŭ ȸ���� ���Ѿ� ��
  - K������ ū ���� ã�Ƴ��� ���� ��й�ȣ�� ������������ ����
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
// ���� ������ ��й�ȣ ����� ��
void get_pass() {
    int cnt = N/4;
    string new_pass = " ";
    for (int i = 0; i < nums.size(); i++) {
        int idx = i % cnt;
        new_pass += nums[i];
        // �簢���� �� �鿡 �����ִ� 16������ ������ ������ ���
        if (idx == cnt-1) {
            bool check = true;
            int val = stoi(new_pass, nullptr, 16);
// cout << "new password candidate: " << new_pass << " in dec: " << val << endl;
            for (int j = 0; j < password.size(); j++) {
                // 16������ 10������ ��ȯ�ϰ� password�� ������ �߰��� ���� �ִ��� �ߺ� üũ
                if (stoi(new_pass, nullptr, 16) == password[j]) {
                    check = false;
                    break;
                }
            }
            // �ߺ��� ������ ��ȯ�� ���� push�ϰ� �ʱ�ȭ
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
        // ȸ�� �� ù ���ڸ� ������ ���ڷ� ��ü
        nums[0] = nums[nums.size()-1];
        // ��� ���� ���ڸ� ���� ���ڷ� ��ȯ
        for (int j = 1; j < nums.size(); j++) {
            tmp = nums[j];
            nums[j] = before;
            before = tmp;
        }
        // �� ��й�ȣ�� ����
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