#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }

    bool pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return false;
        }
        top--;
        return true;
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "After pop, top: " << s.peek() << endl;

    return 0;
}

// Time Complexity:
// push: O(1)
// pop: O(1)
