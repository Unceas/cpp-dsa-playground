#include <bits/stdc++.h>
using namespace std;

int binarySearchRecursive(vector<int>& arr, int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int key = 20;

    int index = binarySearchRecursive(arr, 0, arr.size() - 1, key);

    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found";

    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursion stack
