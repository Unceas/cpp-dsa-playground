#include <bits/stdc++.h>
using namespace std;

// Binary Search works only on sorted arrays
int binarySearch(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int key = 40;

    int index = binarySearch(arr, key);

    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found";

    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
