class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // convert nums to unordered_set(same as Python's set())
        unordered_set<int> nums2(nums.begin(), nums.end());
        // key: number from input array
        // value: length of consecutive sequence with that number as either the upper or lower bound
        // use unordered_map which has O(1) time complexity
        unordered_map<int, int> table;
        int maxVal = 0;
        for (int num : nums2) {
            // get the length of num-1 sequence
            int x;
            auto it1 = table.find(num-1);
            if (it1 != table.end()) {
                x = it1->second;
            } else {
                x = 0;
            }
            // get the length of num+1 sequence
            int y;
            auto it2 = table.find(num+1);
            if (it2 != table.end()) {
                y = it2->second;
            } else {
                y = 0;
            }
            // calculate the current sequence length possible
            int val = x+y+1;
            // set the sequence length for starting index
            // update length at left boundary of merged sequence
            table[num-x] = val;
            // update length at right boundary of merged sequence
            table[num+y] = val;
            maxVal = max(maxVal, val);
        }
        return maxVal;
    }
};