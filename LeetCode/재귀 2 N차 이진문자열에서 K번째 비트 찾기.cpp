class Solution {
public:
    char findKthBit(int n, int k) {
        // 문자열 길이가 1
        if (n == 1) {
            return '0';
        }
        // 
        int len = (1 << n) - 1;
        // cout << len;
        // 중앙 비트 인덱스 구하기: k가 mid와 동일하면 중앙 비트는 항상 1
        int mid = len / 2 + 1;
        if (k == mid) {
            return '1';
        }
        // k가 mid보다 작으면 해당 비트는 첫 절반에 속하므로 n-1(실제 길이는 2^(n-1))만큼 재귀
        if (k < mid) {
            return findKthBit(n-1, k);
        }
        // k가 mid보다 크면 해당 비트는 나머지 절반에 속함
        // 이는 첫 절반을 반전시키기고 뒤집은 것과 동일
        // 해당 절반에서 결과를 반전시키기
        if (findKthBit(n-1, len-k+1) == '0') {
            return '1';
        } else {
            return '0';
        }
    }
};