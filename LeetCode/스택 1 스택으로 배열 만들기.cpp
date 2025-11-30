class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        // 1부터 시작
        int cnt = 1;
        for (int i : target) {
            // 숫자를 건너뛰어야 할 시: 어차피 push는 해야 하므로 pop도 같이 수행
            while (cnt < i) {
                ans.push_back("Push");
                ans.push_back("Pop");
                cnt++;
            }
            // 건너뛰지 않는 경우 push만
            ans.push_back("Push");
            cnt++;
        }
        return ans;
    }
};