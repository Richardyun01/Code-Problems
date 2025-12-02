class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stk; 
        for (int i = 0; i < n; i++) {
            // 새로 등장한 온도가 더 따듯한 경우
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                // 스택에서 인덱스를 꺼내 차이를 배열에 채워넣음
                ans[stk.top()] = i - stk.top();
                stk.pop();
            }
            // 아직 더 따듯한 온도를 만나지 못하면 스택에 저장
            stk.push(i);
        }
        return ans;
    }
};