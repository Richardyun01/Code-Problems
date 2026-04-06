#include<iostream>
using namespace std;
int main() {
    string base, bomb;
    cin >> base >> bomb;
    string ans = "";
    for (auto b : base) {
        ans += b;
        if (ans.size() >= bomb.size()) {
            bool match = true;
            for (int i = 0; i < bomb.size(); i++) {
                if (ans[ans.size() - bomb.size() + i] != bomb[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                // cout << "boom" << endl;
                ans.erase(ans.end() - bomb.size(), ans.end());
            }
        }
    }
    if (ans != "") {
        cout << ans;
    } else {
        cout << "FRULA";
    }
    return 0;
}