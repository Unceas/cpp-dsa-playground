#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void deleteNode(Node*& head, int key) {
    if (head == NULL) return;

    // If head needs to be deleted
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) return;

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    deleteNode(head, 20);

    printList(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
