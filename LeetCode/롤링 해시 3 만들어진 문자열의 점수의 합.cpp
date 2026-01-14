class Solution {
public:
    long long sumScores(string s) {
        long long sum_z = 0;
        for (auto i : z_func(s)) {
            sum_z += i;
        }
        return sum_z + s.size();
    }
    vector<int> z_func(string s) {
        int n = s.size();
        // Z 배열
        vector<int> z(n, 0);
        // Z 배열의 좌우 끝
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            // 현재 인덱스가 z 배열 [l, r] 내부라면 i가 prefix와 일정 부분 일치하는 것이 보장됨
            // 이미 계산된 z[i-l]값 활용 가능
            // i에서 z 배열 끝까지 남은 길이와 대응 위치의 z값(재사용 후보)
            if (i <= r) {
                z[i] = min(r-i+1, z[i-l]);
            }
            // 경계 밖으로 확장 가능한지 비교
            // z 배열 경계 r를 넘으면 보장이 사라지므로 추가로 확장
            // 정확한 LCP 길이가 됨
            while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
                z[i] += 1;
            }
            // z 배열 갱신: 더 멀리 뻗는 매칭을 발견하면 확장
            // 매칭 구간에서 우측 끝이 r보다 크면 갱신
            if (i+z[i]-1 > r) {
                l = i;
                r = i+z[i]-1;
            }
        }
        return z;
    }
};