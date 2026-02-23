#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

bool searchBST(Node* root, int key) {
    if (!root) return false;

    if (root->data == key)
        return true;
    else if (key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int key = 60;

    if (searchBST(root, key))
        cout << "Key Found";
    else
        cout << "Key Not Found";

    return 0;
}

// Average Time Complexity: O(log n)
// Worst Case: O(n)
