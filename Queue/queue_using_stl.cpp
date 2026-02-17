#include <bits/stdc++.h>
using namespace std;

// Queue implementation using STL
int main() {
    queue<int> q;

    // Push elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    q.pop();

    cout << "After pop, front: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;

    return 0;
}

// Time Complexity:
// push: O(1)
// pop: O(1)
