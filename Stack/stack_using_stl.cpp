#include <bits/stdc++.h>
using namespace std;

// Stack implementation using STL
int main() {
    stack<int> st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    // Pop element
    st.pop();

    cout << "Top after pop: " << st.top() << endl;

    cout << "Stack size: " << st.size() << endl;

    return 0;
}

// Time Complexity:
// push: O(1)
// pop: O(1)
// top: O(1)
