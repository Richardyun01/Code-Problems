class MyQueue {
public:
    // 2개의 스택 정의: 주 스택과 큐처럼 접근하게 해주는 부 스택
    stack<int> s1;
    stack<int> s2;
    // 구조체는 무시
    MyQueue() {

    }
    // 스택과 동일
    void push(int x) {
        s1.push(x);
    }
    // 주 스택의 모든 내용물을 부 스택으로 옮기고(이때 순서가 거꾸로가 됨)
    int pop() {
        int n = s1.size();
        for (int i = 0; i < n-1; i++) {
            s2.push(s1.top());
            s1.pop();
        }
        // 큐의 가장 앞(주 스택으로서는 가장 밑, 부 스택으로서는 가장 위)를 가져온 뒤 pop
        int popped = s1.top();
        s1.pop();
        // 다시 주 스택에 넣음
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return popped;
    }
    
    int peek() {
        int n = s1.size();
        // 주 스택의 모든 내용물을 부 스택으로 옮기고(이때 순서가 거꾸로가 됨)
        for (int i = 0; i < n-1; i++) {
            s2.push(s1.top());
            s1.pop();
        }
        // 큐의 가장 앞을 가져오되 제거하지는 않음
        int top = s1.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return top;
    }
    // 스택과 동일
    bool empty() {
        return s1.empty();
    }
};