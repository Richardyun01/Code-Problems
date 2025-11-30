class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string s : tokens) {
            if (s == "+") {
                int tmp1 = stk.top();
                stk.pop();
                int tmp2 = stk.top();
                stk.pop();
                // cout << "sum " << tmp2 << " + " << tmp1 << ": " << tmp2+tmp1 << endl;
                stk.push(tmp2+tmp1);
            } else if (s == "-") {
                int tmp1 = stk.top();
                stk.pop();
                int tmp2 = stk.top();
                stk.pop();
                // cout << "sub " << tmp2 << " - " << tmp1 << ": " << tmp2-tmp1 << endl;
                stk.push(tmp2-tmp1);
            } else if (s == "/") {
                int tmp1 = stk.top();
                stk.pop();
                int tmp2 = stk.top();
                stk.pop();
                // cout << "div " << tmp2 << " / " << tmp1 << ": " << tmp2/tmp1 << endl;
                stk.push(tmp2/tmp1);
            } else if (s == "*") {
                int tmp1 = stk.top();
                stk.pop();
                int tmp2 = stk.top();
                stk.pop();
                // cout << "mul " << tmp2 << " * " << tmp1 << ": " << tmp2*tmp1 << endl;
                stk.push(tmp2*tmp1);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};