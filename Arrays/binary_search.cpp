// Binary Search Algorithm
// Works on sorted arrays only
// Efficient searching technique using divide and conquer
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

/**
 * Performs binary search on a sorted array to find the target element.
 *
 * @param arr   Reference to a sorted vector of integers (ascending order).
 * @param target The value to search for in the array.
 * @return Index of target if found, otherwise -1.
 */
int binarySearch(const vector<int> &arr, int target) {
    int left = 0;               // Left boundary of the current search range
    int right = (int)arr.size() - 1; // Right boundary of the current search range

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids potential overflow

        if (arr[mid] == target) {
            return mid;         // Target found at index mid
        } else if (arr[mid] < target) {
            left = mid + 1;     // Search in the right half
        } else {
            right = mid - 1;    // Search in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int index = binarySearch(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found in array" << endl;
    }

    return 0;
}
