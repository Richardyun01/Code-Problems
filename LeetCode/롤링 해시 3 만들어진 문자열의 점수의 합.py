class Solution:
    def sumScores(self, s: str) -> int:
        def z_func(s):
            n = len(s)
            # Z 배열
            z = [0]*n
            # Z 배열의 좌우 끝
            l, r = 0, 0
            for i in range(1, n):
                # 현재 인덱스가 z 배열 [l, r] 내부라면 i가 prefix와 일정 부분 일치하는 것이 보장됨
                # 이미 계산된 z[i-l]값 활용 가능
                # i에서 z 배열 끝까지 남은 길이와 대응 위치의 z값(재사용 후보) 중 하한을 초기값으로 사용
                if i <= r:
                    z[i] = min(r-i+1, z[i-l])
                # 경계 밖으로 확장 가능한지 비교
                # z 배열 경계 r를 넘으면 보장이 사라지므로 추가로 확장
                # 정확한 LCP 길이가 됨
                while i + z[i] < n and s[z[i]] == s[i+z[i]]:
                    z[i] += 1
                # z 배열 갱신: 더 멀리 뻗는 매칭을 발견하면 확장
                # 매칭 구간에서 우측 끝이 r보다 크면 갱신 
                if i + z[i] - 1 > r:
                    l, r= i, i + z[i] - 1
            return z
        return sum(z_func(s)) + len(s)