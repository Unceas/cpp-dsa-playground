#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool enqueue(int x) {
        if (rear >= MAX - 1) {
            cout << "Queue Overflow\n";
            return false;
        }
        arr[++rear] = x;
        return true;
    }

    bool dequeue() {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return false;
        }
        front++;
        return true;
    }

    int peek() {
        if (front > rear) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    cout << "After dequeue, front: " << q.peek() << endl;

    return 0;
}

// Time Complexity:
// enqueue: O(1)
// dequeue: O(1)
