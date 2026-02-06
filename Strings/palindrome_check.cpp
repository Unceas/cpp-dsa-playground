#include <bits/stdc++.h>
using namespace std;

// Check if a string is a palindrome
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s = "level";

    if (isPalindrome(s))
        cout << "Palindrome";
    else
        cout << "Not a palindrome";

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
