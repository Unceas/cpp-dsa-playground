#include <iostream>
#include <algorithm>
using namespace std;

// Time Complexity: O(n) - single pass through array
// Space Complexity: O(1) - only using one variable for max
int findMax(int arr[], int n) {
    int mx = arr[0];
    for(int i = 1; i < n; i++) {
        mx = max(mx, arr[i]);
    }
    return mx;
}

int main() {
    int arr[] = {12, 5, 30, 7, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum element: " << findMax(arr, n);
    return 0;
}
