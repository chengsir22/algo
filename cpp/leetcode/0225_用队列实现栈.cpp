//
// Created by 鲁红呈 on 2023/10/21.
//

#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> que;

    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        while (size != 1) {
            que.push(que.front());
            que.pop();
            size--;
        }
        int res = que.front();
        que.pop();
        return res;
    }

    int top() {
        return que.back();
    }

    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */