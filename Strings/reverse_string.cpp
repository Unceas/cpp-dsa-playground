#include <bits/stdc++.h>
using namespace std;

// Reverse a string using two-pointer technique
string reverseString(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

int main() {
    string s = "hello";

    cout << "Reversed string: " << reverseString(s);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
