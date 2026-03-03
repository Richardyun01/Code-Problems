class Solution:
    def friendRequests(self, n: int, restrictions: List[List[int]], requests: List[List[int]]) -> List[bool]:
        # 제한 관계를 O(1)로 빠르게 조회하기 위해 set으로 저장
        rests = set([tuple(r) for r in restrictions])
        # 각 사람이 속한 친구 그룹을 저장하는 딕셔너리
        sets = {}
        results = []

        # frozenset: 변경 불가능한 속성이 추가된 set(Read only)
        # 딕셔너리 value로 안전하게 공유가 가능하고 union 결과를 여러 key에 동일 객체로 할당 가능
        for request in requests:
            # 현재 두 사람의 소속 집합 탐색
            # 이미 그룹이 있으면 그 그룹, 없으면 자기 자신만 포함된 집합
            from_set = sets.get(request[0], frozenset([request[0]]))
            to_set = sets.get(request[1], frozenset([request[1]]))

            # 제한 위반 검사: from_set과 to_set의 쌍 중 하나라도 rests에 있는지 검사
            if any((x, y) in rests or (y, x) in rests for x, y in itertools.product(from_set, to_set)):
                results.append(False)
            else:
                # 위반이 없으면 Union 수행
                # 모든 구성원에게 같은 집합을 매핑
                results.append(True)
                union = from_set.union(to_set)
                for num in union:
                    sets[num] = union
        
        return results