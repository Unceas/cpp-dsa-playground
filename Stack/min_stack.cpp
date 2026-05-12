#include <bits/stdc++.h>
using namespace std;

// Min Stack
class MinStack {

    stack<int> st;
    stack<int> minSt;

public:

    void push(int val) {

        st.push(val);

        if(minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }

    void pop() {

        if(st.top() == minSt.top())
            minSt.pop();

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {

    MinStack ms;

    ms.push(5);
    ms.push(2);
    ms.push(7);

    cout << ms.getMin() << endl;

    ms.pop();

    cout << ms.getMin();

    return 0;
}
