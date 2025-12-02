class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        stack<int> stk;
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int top_idx = stk.top();
                stk.pop();
                int h = heights[top_idx];
                int width;
                // cout << "top_idx: " << top_idx << endl;
                // cout << "height: " << h << endl;
                if (stk.empty()) {
                    width = i;
                } else {
                    width = i - stk.top() - 1;
                }
                // cout << "width: " << width << endl;
                int tmp_area = h * width;
                // cout << "tmp_area: " << tmp_area << endl;
                if (max_area < tmp_area) {
                    max_area = tmp_area;
                }
                // cout << "max_area: " << max_area << endl;
            }
            stk.push(i);
            // cout << "=============" << endl;
        }
        while (!stk.empty()) {
            int top_idx = stk.top();
            stk.pop();
            int h = heights[top_idx];
            int width;
            if (stk.empty()) {
                width = heights.size();
            } else {
                width = heights.size() - stk.top() - 1;
            }
            // cout << "height: " << h << endl;
            // cout << "width: " << width << endl;
            int tmp_area = h * width;
            if (max_area < tmp_area) {
                max_area = tmp_area;
            }
            // cout << "tmp_area: " << tmp_area << endl;
            // cout << "max_area: " << max_area << endl;
        }
        return max_area;
    }
};