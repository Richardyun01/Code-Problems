// 이분탐색
// 임의의 배열 start를 정의하고 intervals의 [i번의 start, i]와 같은 형태로 값을 담음
// i번의 start를 기준으로 start 배열 정렬
// intervals 내에서 end 값에 대해 조건을 만족하는 start 탐색
class Solution {
public:
    // 입력으로 주어지는 intervals 배열들의 start를 담음
    // [i번의 start, i] 형태
    vector<pair<int, int>> start;
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        // start 배열에 값 담고 이분탐색 위해 정렬
        for (int i = 0; i < intervals.size(); i++) {
            start.emplace_back(intervals[i][0], i);
        }
        sort(start.begin(), start.end());
        int n = intervals.size();
        // 이분탐색 진행
        res.reserve(n);
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            res.push_back(bs(end));
        }
        return res;
    }

    // 이분탐색
    int bs(int n) {
        // 인덱스 정의
        int l = 0;
        int r = start.size() - 1;
        int res = -1;

        // start의 값은 unique함: end와 일치하는 값 탐색 시 인덱스 리턴
        // start가 더 클 경우: r를 m-1로 설정해 작은 값 탐색
        // start가 더 작을 경우: l을 m+1로 설정해 다시 탐색
        while (l <= r) {
            int m = (l + r) / 2;
            if (start[m].first == n) {
                return start[m].second;
            } else if (start[m].first >= n) {
                r = m - 1;
                res = start[m].second;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};