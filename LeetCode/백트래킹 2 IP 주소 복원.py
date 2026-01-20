# DFS 방식의 백트래킹
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        # 유효한 IP 주소'들'을 담음
        ans = []
        # 아예 불가능한 경우
        if len(s) > 12 or len(s) < 4:
            return ans
        def backtrack(start, seg):
            # 각 블럭 4개가 완성됨
            if len(seg) == 4:
                # 모든 숫자를 사용했을 경우
                # 유효한 IP 주소이므로 블럭들을 .으로 연결하고 저장
                if start == len(s):
                    tmp = '.'.join(seg)
                    # print('final seg', seg)
                    ans.append(tmp)
                # 유효하지 않은 IP 주소
                else:
                    # print('invalid', seg)
                    return
            # 아직 블럭 4개가 완성되지 않으면
            # 새 블럭 만들기
            else:
                # 문자열의 현재 시작 인덱스에서 끝까지
                # 시작 인덱스는 블럭마다 지속적으로 갱신됨
                for end in range(start+1, len(s)+1):
                    # 현재 블럭을 숫자로 변환
                    num = int(s[start:end])
                    # 현재 블럭의 길이가 0이고 그 값이 10 미만인 경우:
                    # 앞이 0인 두 자리 수 -> 프루닝함
                    if end-start == 2 and num < 10:
                        # print('returned, seg', seg)
                        return
                    # 블럭 값이 255보다 클 경우:
                    # 더 커지는 것을 피하기 위해 루프 종료
                    if num > 255:
                        # print('overcount, seg', seg)
                        break
                    # print('seg', seg)
                    # 재귀로 반복
                    # 현재 인덱스가 새로운 블럭의 새로운 인덱스가 됨
                    # 이전의 블럭들은 담겨 있는 상태
                    backtrack(end, seg+[str(num)])
        backtrack(0, [])
        return ans