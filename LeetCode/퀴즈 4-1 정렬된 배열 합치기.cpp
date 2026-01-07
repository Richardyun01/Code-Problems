// 투 포인터
// num1에서 유효한 인덱스를 포인터 i로 저장
// num2에서 유효한 인덱스를 포인터 j로 저장
// nums1 배열 가장 마지막 인덱스를 포인터 k로 저장
// nums1 배열에서 가장 큰 값과 nums2 배열에서 가장 큰 값을 비교
// 큰 값은 두 배열 병합 시 가장 큰 요소이므로 nums1의 가장 마지막 인덱스에서 가장 앞 인덱스 순으로 차례대로 위치
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};