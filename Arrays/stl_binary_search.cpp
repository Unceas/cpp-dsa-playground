// STL Binary Search using binary_search()
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {5, 10, 15, 20, 25};

    int key = 15;

    if (binary_search(arr.begin(), arr.end(), key))
        cout << "Element found using STL";
    else
        cout << "Element not found";

    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
