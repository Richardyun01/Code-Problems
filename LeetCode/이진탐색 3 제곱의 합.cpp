class Solution {
public:
    bool judgeSquareSum(int c) {
        // 상한값은 c의 제곱근
        int l = 0, r = sqrt(c);
        while (l <= r) {
            // 내부에서 가상의 합을 구해 c와 비교
            // 더 크면 r를 감소, 더 작으면 l을 증가
            long long m = (long long)(l*l)+(long long)(r*r);
            if (m == c) {
                return true;
            } else if (m > c) {
                r--;
            } else {
                l++;
            }
        }
        return false;
    }
};