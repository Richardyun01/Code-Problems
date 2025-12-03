class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        // 배열의 길이가 3 이상이어야 산이 될 수 있음
        if (n < 3) {
            return false;
        }
        int l = 0;
        int r = n-1;
        // 좌측 포인터를 우측으로 이동해 증가하는지 체크
        while (l+1 < n && arr[l] < arr[l+1]) {
            l++;
        }
        // 우측 포인터를 좌측으로 이동해 감소하는지 체크
        while (r > 0 && arr[r] < arr[r-1]) {
            r--;
        }
        // 좌측과 우측이 둘 다 움직였고 동일하면 산
        bool check = (l > 0 && r < n-1 && l == r);
        return check;
    }
};