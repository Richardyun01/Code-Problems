class Solution {
public:
    vector<int> plus(vector<int>& digits, int n) {
        if (digits[n] < 9) {
            digits[n] += 1;
            return digits;
        } else {
            digits[n] = 0;
            if (n == 0) {
                // 벡터 맨 앞에 1 추가
                digits.insert(digits.begin(), 1);
                return digits;
            } else {
                n--;
                // 재귀하여 다음 자리로 넘어감
                return plus(digits, n);
            }
        }
    }
    vector<int> plusOne(vector<int>& digits) {
        return plus(digits, digits.size()-1);
    }
};