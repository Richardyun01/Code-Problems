/*
  접근 방법 및 구현
  - 입학 연도와 (문제 개수, 성씨)를 별도의 벡터로 정의
  - 각각 입력받아 저장할 때 연도는 100으로 나눈 나머지, 성씨는 맨 앞글자만 저장하면 됨
  - 연도를 출력할 때 가장 앞의 3개를 가져오되 형식을 편하게 맞추기 위해서 printf 사용
*/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> years;
vector<pair<int, char>> probs_init;
bool compare(const pair<int, char>& a, const pair<int, char>& b) {
    return a.first > b.first;
}
int main() {
    for (int i = 0; i < 3; i++) {
        int p, y; string s;
        if (!(cin >> p >> y >> s)) return 0;
        years.push_back(y % 100);
        probs_init.push_back({p, s[0]});
    }
    sort(years.begin(), years.end());
    printf("%02d%02d%02d\n", years[0], years[1], years[2]);
    
    sort(probs_init.begin(), probs_init.end(), compare);
    for (auto &e : probs_init) {
        cout << e.second;
    }
    return 0;
}