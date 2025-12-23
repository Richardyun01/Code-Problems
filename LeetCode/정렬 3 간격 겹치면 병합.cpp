class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        // sorting: 람다식으로 [0]을 기준으로 정렬
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        // 초기 prev
        vector<int> prev = intervals[0];
        for (auto interval : intervals) {
            // 현재 interval의 [0]이 prev의 [1]보다 클 시 오버랩됨
            if (interval[0] <= prev[1]) {
                prev[1] = max(prev[1], interval[1]);
            // 오버랩되지 않을 경우
            } else {
                ans.push_back(prev);
                prev = interval;
            }
        }
        ans.push_back(prev);
        return ans;
    }
};