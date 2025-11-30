class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int twice, miss;
        // sort(nums.begin(), nums.end());
        // 중복 숫자 찾기+방문 표시
        for (int i = 0; i < nums.size(); i++) {
            // 해당 값의 인덱스
            int idx = abs(nums[i])-1;
            // 음수일 경우: 이미 방문함
            if (nums[idx] < 0) {
                twice = abs(nums[i]);
            // 양수일 경우: 방문 체크
            } else {
                nums[idx] *= -1;
            }
        }
        // 없는 숫자 찾기
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                miss = i+1;
                break;
            }
        }
        ans.push_back(twice);
        ans.push_back(miss);
        return ans;
    }
};